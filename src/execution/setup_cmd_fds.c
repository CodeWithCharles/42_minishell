/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmd_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:28 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/12 16:38:05 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	setup_infile_fd(
	t_cmd *cmd
)
{
	t_redir	*curr_redir;

	if (!cmd->redir_in_list)
		curr_redir = NULL;
	else
		curr_redir = ft_lastredir(cmd->redir_in_list);
	if (!curr_redir || curr_redir->type == REDIR_NONE)
		return (RET_OK);
	if (curr_redir->type == REDIR_HEREDOC)
		cmd->fd_in = open(curr_redir->file, O_RDONLY, 0644);
	else if (curr_redir->type == REDIR_INPUT)
		cmd->fd_in = open(curr_redir->file, O_RDONLY, 0644);
	if (cmd->fd_in == INVALID_FD)
		return (RET_ERR);
	return (RET_OK);
}

int	setup_outfile_fd(
	t_cmd *cmd
)
{
	int		out_flags;
	t_redir	*curr_redir;

	if (!cmd->redir_out_list)
		curr_redir = NULL;
	else
		curr_redir = ft_lastredir(cmd->redir_out_list);
	if (!curr_redir || curr_redir->type == REDIR_NONE)
		return (RET_OK);
	out_flags = O_WRONLY | O_CREAT;
	if (curr_redir->type == REDIR_APPEND)
		cmd->fd_out = open(curr_redir->file, out_flags | O_APPEND, 0644);
	else if (curr_redir->type != REDIR_NONE)
		cmd->fd_out = open(curr_redir->file, out_flags | O_TRUNC, 0644);
	if (cmd->fd_out == INVALID_FD && curr_redir->type != REDIR_NONE)
		return (RET_ERR);
	return (RET_OK);
}

int	setup_cmd_fd_io(
	t_cmd *cmd
)
{
	if (setup_infile_fd(cmd) == RET_ERR)
		return (RET_ERR);
	if (setup_outfile_fd(cmd) == RET_ERR)
		return (RET_ERR);
	return (RET_OK);
}
