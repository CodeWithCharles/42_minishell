/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:23 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/12 12:36:44 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

static int	_setup_exec_ctx(
	t_cmd **cmd_list,
	t_executing_ctx *exec_ctx
)
{
	exec_ctx->cmd_count = ft_cmd_count(cmd_list);
	if (exec_ctx->cmd_count == 0)
		return (RET_OK);
	exec_ctx->last_fd = -1;
	exec_ctx->cmd_list = cmd_list;
	exec_ctx->curr_idx = -1;
	return (RET_OK);
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

static int	_check_should_fork(
	t_cmd **cmd_list,
	t_executing_ctx *exec_ctx
)
{
	if (exec_ctx->cmd_count != 1
		|| exec_ctx->curr_idx != exec_ctx->cmd_count - 1)
		return (0);
	if (ft_strcmp(cmd_list[exec_ctx->curr_idx]->cmd_name, "exit") == 0
		|| ft_strcmp(cmd_list[exec_ctx->curr_idx]->cmd_name, "cd") == 0
		|| ft_strcmp(cmd_list[exec_ctx->curr_idx]->cmd_name, "unset") == 0
		|| ft_strcmp(cmd_list[exec_ctx->curr_idx]->cmd_name, "export") == 0)
		return (1);
	return (0);
}

void	clean_exec_ctx(
	t_executing_ctx *exec_ctx
)
{
	if (exec_ctx->cmd_list)
		ft_free_cmd_list(exec_ctx->cmd_list, exec_ctx->cmd_count);
}

void	execute_pipeline(
	t_minishell_ctx *ctx,
	t_cmd **cmd_list
)
{
	t_executing_ctx	exec_ctx;
	int				p_fd[2];

	exec_ctx = (t_executing_ctx){};
	if (_setup_exec_ctx(cmd_list, &exec_ctx) == RET_ERR
		|| exec_ctx.cmd_count <= 0)
		return ;
	check_redir_files(ctx, &exec_ctx, cmd_list);
	while (++exec_ctx.curr_idx < exec_ctx.cmd_count)
	{
		if (!cmd_list[exec_ctx.curr_idx]->cmd_name)
			continue ;
		if (_check_should_fork(cmd_list, &exec_ctx))
			execute_builtin(ctx, &exec_ctx, cmd_list[exec_ctx.curr_idx], 0);
		else
		{
			if (pipe(p_fd) == -1)
				print_gen_error(ctx, ERR_PIPING);
			else
				fork_command(ctx, cmd_list[exec_ctx.curr_idx],
					&exec_ctx, p_fd);
		}
	}
	_wait_for_childrens();
}
