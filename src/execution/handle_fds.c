/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:23 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 14:01:00 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	_close_fds_if_open(t_cmd *cmd)
{
	if (cmd->fd_in != INVALID_FD)
	{
		close(cmd->fd_in);
		cmd->fd_in = INVALID_FD;
	}
	if (cmd->fd_out != INVALID_FD)
	{
		close(cmd->fd_out);
		cmd->fd_out = INVALID_FD;
	}
}

// Header implementations

int	handle_redirection(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	if (cmd->redir_in.type != REDIR_NONE)
		cmd->fd_in = open(cmd->redir_in.file, O_RDONLY);
	if (cmd->redir_out.type != REDIR_NONE)
		cmd->fd_out = open(cmd->redir_out.file,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->redir_out.type != REDIR_NONE && cmd->fd_out == INVALID_FD)
	{
		_close_fds_if_open(cmd);
		return (print_gen_error(ctx, ERR_COULD_NOT_OPEN_OUT), RET_ERR);
	}
	if (cmd->redir_in.type != REDIR_NONE && cmd->fd_in == -1)
	{
		print_gen_error(ctx, ERR_COULD_NOT_OPEN_IN);
		cmd->fd_in = open(TMP_EMPTY_PATH, O_RDONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd->fd_in == INVALID_FD)
		{
			_close_fds_if_open(cmd);
			return (print_gen_error(ctx, ERR_COULD_NOT_OPEN_EMP), RET_ERR);
		}
	}
	return (RET_OK);
}
