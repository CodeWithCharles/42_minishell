/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:05 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/12 12:26:17 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_redir_in_files(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	t_list	*redir_list;
	t_redir	*curr_redir;

	redir_list = cmd->redir_in_list;
	while (redir_list)
	{
		curr_redir = ft_ltor(redir_list);
		if (curr_redir->type == REDIR_INPUT
			&& access(curr_redir->file, R_OK) != 0)
		{
			print_arg_error(ctx, ERR_COULD_NOT_OPEN_IN, curr_redir->file);
			return (RET_ERR);
		}
		else if (curr_redir->type == REDIR_HEREDOC)
			if (handle_here_doc(ctx, &curr_redir) == RET_ERR)
				return (RET_ERR);
		redir_list = redir_list->next;
	}
	return (RET_OK);
}

static int	check_redir_out_files(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	t_list	*redir_list;
	t_redir	*curr_redir;
	int		tmp_fd;
	int		out_flags;

	redir_list = cmd->redir_out_list;
	while (redir_list)
	{
		curr_redir = ft_ltor(redir_list);
		out_flags = O_WRONLY | O_CREAT | O_TRUNC;
		if (curr_redir->type == REDIR_APPEND)
			out_flags = (out_flags & ~O_TRUNC) | O_APPEND;
		tmp_fd = open(curr_redir->file, out_flags, 0644);
		if (tmp_fd == -1)
			return (print_arg_error(ctx, ERR_COULD_NOT_OPEN_OUT,
					curr_redir->file), RET_ERR);
		else
			close(tmp_fd);
		redir_list = redir_list->next;
	}
	return (RET_OK);
}

int	check_redir_files(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd **cmd_list
)
{
	int	i;

	i = -1;
	while (++i < exec_ctx->cmd_count)
	{
		if (cmd_list[i]->redir_in_list
			&& check_redir_in_files(ctx, cmd_list[i]))
		{
			free(cmd_list[i]->cmd_name);
			cmd_list[i]->cmd_name = NULL;
			continue ;
		}
		if (cmd_list[i]->redir_out_list
			&& check_redir_out_files(ctx, cmd_list[i]))
		{
			free(cmd_list[i]->cmd_name);
			cmd_list[i]->cmd_name = NULL;
			continue ;
		}
	}
	return (RET_OK);
}
