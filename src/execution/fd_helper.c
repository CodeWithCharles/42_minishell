/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:28 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 19:41:17 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	_setup_infile_fd(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	if (cmd->redir_in.type == REDIR_HEREDOC)
		handle_here_doc(ctx, cmd);
	else if (cmd->redir_in.type != REDIR_NONE)
		cmd->fd_in = open(cmd->redir_in.file, O_RDONLY, 0644);
	if (cmd->fd_in == INVALID_FD)
	{
		print_gen_error(ctx, ERR_COULD_NOT_OPEN_IN);
		cmd->fd_in = open(TMP_EMPTY_PATH, O_RDONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd->fd_in == INVALID_FD)
			return (close_fds_if_open(cmd), RET_ERR);
	}
	return (RET_OK);
}

static int	_setup_outfile_fd(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	int	out_flags;

	out_flags = O_WRONLY | O_CREAT;
	if (cmd->redir_out.type == REDIR_APPEND)
		cmd->fd_out = open(cmd->redir_out.file, out_flags | O_APPEND, 0644);
	else if (cmd->redir_out.type != REDIR_NONE)
		cmd->fd_out = open(cmd->redir_out.file, out_flags | O_TRUNC, 0644);
	if (cmd->fd_out == INVALID_FD)
	{
		print_gen_error(ctx, ERR_COULD_NOT_OPEN_OUT);
		close_fds_if_open(cmd);
		return (RET_ERR);
	}
	return (RET_OK);
}

int	setup_cmd_fd_io(
	t_minishell_ctx *ctx,
	t_list *cmd_list
)
{
	t_list	*node;
	t_cmd	*cmd;

	node = cmd_list;
	while (node)
	{
		cmd = (t_cmd *)node->content;
		if (cmd->redir_in.file && _setup_infile_fd(ctx, cmd) == RET_ERR)
			return (RET_ERR);
		if (cmd->redir_out.file && _setup_outfile_fd(ctx, cmd) == RET_ERR)
			return (RET_ERR);
		node = node->next;
	}
	return (RET_OK);
}
