/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:23 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/04 16:26:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

static int	_setup_exec_ctx(
	t_minishell_ctx *ctx,
	t_cmd *cmd_list,
	t_executing_ctx *exec_ctx
)
{
	exec_ctx->cmd_count = ft_cmd_count(cmd_list);
	if (exec_ctx->cmd_count == 0)
		return (RET_OK);
	exec_ctx->pids = malloc(sizeof(int) * exec_ctx->cmd_count);
	if (!exec_ctx->pids)
		return (print_gen_error(ctx, ERR_INT_ERR_ALLOC), RET_ERR);
	if (exec_ctx->cmd_count > 0)
	{
		exec_ctx->pipes = malloc(sizeof(int [2]) * (exec_ctx->cmd_count));
		if (!exec_ctx->pipes)
		{
			print_gen_error(ctx, ERR_INT_ERR_ALLOC);
			return (free(exec_ctx->pids), RET_ERR);
		}
		if (setup_pipes(ctx, exec_ctx->cmd_count, exec_ctx->pipes) == RET_ERR)
			return (free(exec_ctx->pids), free(exec_ctx->pipes), RET_ERR);
	}
	return (setup_cmd_fd_io(ctx, cmd_list, exec_ctx->cmd_count));
}

void	_clean_exec_ctx(
	t_executing_ctx *exec_ctx
)
{
	if (exec_ctx->pids)
		free(exec_ctx->pids);
	if (exec_ctx->pipes)
	{
		close_pipes(exec_ctx->cmd_count, exec_ctx->pipes);
		free(exec_ctx->pipes);
	}
}

static void	_wait_for_childrens(void)
{
	int		cur_status;
	int		final_status;
	pid_t	cur_pid;
	pid_t	prev_pid;

	final_status = 0;
	prev_pid = waitpid(-1, &final_status, 0);
	while (prev_pid > 0)
	{
		cur_pid = waitpid(-1, &cur_status, 0);
		if (prev_pid < cur_pid)
			final_status = cur_status;
		prev_pid = cur_pid;
	}
	if (final_status == 131)
		ft_putstr_fd("Quit (core dumped)\n", 2);
	ft_last_exit_code((int)(final_status % 255));
}

int	check_exit(
	t_cmd *cmd_list,
	t_executing_ctx *exec_ctx
)
{
	if (ft_strcmp(cmd_list[exec_ctx->curr_idx].cmd_name, "exit") == 0
		&& !cmd_list[exec_ctx->curr_idx + 1].cmd_name)
		return (1);
	return (0);
}

void	execute_pipeline(
	t_minishell_ctx *ctx,
	t_cmd *cmd_list
)
{
	t_executing_ctx	exec_ctx;

	exec_ctx = (t_executing_ctx){};
	if (_setup_exec_ctx(ctx, cmd_list, &exec_ctx) == RET_ERR
		|| exec_ctx.cmd_count <= 0)
		return ;
	while (exec_ctx.curr_idx < exec_ctx.cmd_count)
	{
		if (check_exit(cmd_list, &exec_ctx))
			execute_builtin(ctx, &exec_ctx, &cmd_list[exec_ctx.curr_idx], NULL);
		else if (fork_command(ctx,
				&cmd_list[exec_ctx.curr_idx], &exec_ctx) == RET_ERR)
		{
			if (exec_ctx.curr_idx + 1 < exec_ctx.cmd_count
				&& cmd_list[exec_ctx.curr_idx + 1].redir_in.type == REDIR_NONE)
			{
				cmd_list[exec_ctx.curr_idx + 1].redir_in.type = REDIR_EMPTY;
				cmd_list[exec_ctx.curr_idx + 1].redir_in.file
					= ft_strdup(TMP_EMPTY_PATH);
			}
		}
		++(exec_ctx.curr_idx);
	}
	_wait_for_childrens();
	_clean_exec_ctx(&exec_ctx);
}
