/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:43:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/04 15:50:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

void	setup_redirections(
	t_cmd *cmd,
	t_executing_ctx *exec_ctx
)
{
	if (cmd->fd_in != INVALID_FD && cmd->redir_in.type != REDIR_NONE)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out != INVALID_FD && cmd->redir_out.type != REDIR_NONE)
		dup2(cmd->fd_out, STDOUT_FILENO);
	else if (exec_ctx->curr_idx < exec_ctx->cmd_count)
		dup2(exec_ctx->pipes[exec_ctx->curr_idx][1], STDOUT_FILENO);
	if (exec_ctx->pipes[exec_ctx->curr_idx][0] != INVALID_FD)
		close(exec_ctx->pipes[exec_ctx->curr_idx][0]);
	if (exec_ctx->pipes[exec_ctx->curr_idx][1] != INVALID_FD)
		close(exec_ctx->pipes[exec_ctx->curr_idx][1]);
	if (cmd->fd_in != INVALID_FD)
		close(cmd->fd_in);
	if (cmd->fd_out != INVALID_FD)
		close(cmd->fd_out);
}

int	setup_pipes(
	t_minishell_ctx *ctx,
	int cmd_count,
	int (*pipes)[2]
)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		if (pipe(pipes[i]) == -1)
		{
			close_pipes(cmd_count, pipes);
			return (print_gen_error(ctx, ERR_PIPING), RET_ERR);
		}
		++i;
	}
	return (RET_OK);
}
