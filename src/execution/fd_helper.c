/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:28 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/05 11:08:31 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	setup_infile_fd(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	if (cmd->redir_in.type == REDIR_NONE)
		return (RET_OK);
	if (cmd->redir_in.type == REDIR_HEREDOC)
		handle_here_doc(ctx, cmd);
	else if (cmd->redir_in.type != REDIR_NONE)
	{
		cmd->fd_in = open(cmd->redir_in.file, O_RDONLY, 0644);
		if (cmd->fd_in == INVALID_FD)
		{
			print_gen_error(ctx, ERR_COULD_NOT_OPEN_IN);
			return (RET_ERR);
		}
	}
	return (RET_OK);
}

int	setup_outfile_fd(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	int	out_flags;

	if (cmd->redir_out.type == REDIR_NONE)
		return (RET_OK);
	out_flags = O_WRONLY | O_CREAT;
	if (cmd->redir_out.type == REDIR_APPEND)
		cmd->fd_out = open(cmd->redir_out.file, out_flags | O_APPEND, 0644);
	else if (cmd->redir_out.type != REDIR_NONE)
		cmd->fd_out = open(cmd->redir_out.file, out_flags | O_TRUNC, 0644);
	if (cmd->fd_out == INVALID_FD && cmd->redir_out.type != REDIR_NONE)
	{
		print_gen_error(ctx, ERR_COULD_NOT_OPEN_OUT);
		return (RET_ERR);
	}
	return (RET_OK);
}

int	setup_cmd_fd_io(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	if (cmd->redir_in.file
		&& setup_infile_fd(ctx, cmd) == RET_ERR)
		return (RET_ERR);
	if (cmd->redir_out.file
		&& setup_outfile_fd(ctx, cmd) == RET_ERR)
		return (RET_ERR);
	return (RET_OK);
}
