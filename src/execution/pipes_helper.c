/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:43:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/05 11:41:30 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

static int	redirect_input(
	t_cmd *cmd,
	int prev_fd
)
{
	if (cmd->redir_in.type == REDIR_NONE)
		return (dup2(prev_fd, STDIN_FILENO), close(prev_fd), RET_OK);
	if (prev_fd != 0)
		close(prev_fd);
	if (cmd->fd_in == INVALID_FD)
		return (RET_ERR);
	return (dup2(cmd->fd_in, STDIN_FILENO), close(cmd->fd_in), RET_OK);
}

static int	redirect_output(
	t_executing_ctx *exec_ctx,
	t_cmd *cmd,
	int p_fd[2]
)
{
	if (cmd->redir_out.type == REDIR_NONE
		&& exec_ctx->curr_idx == exec_ctx->cmd_count - 1)
		return (RET_OK);
	if (cmd->redir_out.type == REDIR_NONE)
		return (dup2(p_fd[1], STDOUT_FILENO), RET_OK);
	if (cmd->fd_out == INVALID_FD)
		return (dup2(p_fd[1], STDOUT_FILENO), RET_ERR);
	return (dup2(cmd->fd_out, STDOUT_FILENO), close(cmd->fd_out), RET_OK);
}

int	setup_redirections(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd *cmd,
	int p_fd[2]
)
{
	setup_cmd_fd_io(ctx, cmd);
	if (redirect_input(cmd, exec_ctx->last_fd) == RET_ERR)
		return (close(p_fd[0]), close(p_fd[1]), RET_ERR);
	if (redirect_output(exec_ctx, cmd, p_fd) == RET_ERR)
		return (close(p_fd[0]), close(p_fd[1]), RET_ERR);
	return (close(p_fd[0]), close(p_fd[1]), RET_OK);
}
