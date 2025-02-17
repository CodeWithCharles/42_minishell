/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:05 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 17:12:21 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Static prototypes

static int	check_redir_in(
				t_minishell_ctx *ctx,
				t_redir *curr_redir);

static int	check_redir_out(
				t_minishell_ctx *ctx,
				t_redir *curr_redir);

static int	check_redirs_valid(
				t_minishell_ctx *ctx,
				t_list *redir_list);

// Header implementations

int	check_cmds_redirs(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd **cmd_list
)
{
	int	i;

	i = -1;
	while (++i < exec_ctx->cmd_count)
	{
		if (cmd_list[i] && cmd_list[i]->redir_list
			&& check_redirs_valid(ctx, cmd_list[i]->redir_list) == RET_ERR)
		{
			free(cmd_list[i]->cmd_name);
			cmd_list[i]->cmd_name = NULL;
		}
	}
	return (RET_OK);
}

// Static implementations

static int	check_redir_in(
	t_minishell_ctx *ctx,
	t_redir *curr_redir
)
{
	if (curr_redir->type == REDIR_INPUT
		&& access(curr_redir->file, R_OK) != 0)
	{
		print_arg_error(ctx, ERR_COULD_NOT_OPEN_IN, curr_redir->file);
		return (RET_ERR);
	}
	else if (curr_redir->type == REDIR_HEREDOC)
		if (handle_here_doc(ctx, &curr_redir) == RET_ERR)
			return (RET_ERR);
	return (RET_OK);
}

static int	check_redir_out(
	t_minishell_ctx *ctx,
	t_redir *curr_redir
)
{
	int		tmp_fd;
	int		out_flags;

	out_flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (curr_redir->type == REDIR_APPEND)
		out_flags = (out_flags & ~O_TRUNC) | O_APPEND;
	tmp_fd = open(curr_redir->file, out_flags, 0644);
	if (tmp_fd == -1)
		return (print_arg_error(ctx, ERR_COULD_NOT_OPEN_OUT,
				curr_redir->file), RET_ERR);
	else
		close(tmp_fd);
	return (RET_OK);
}

static int	check_redirs_valid(
	t_minishell_ctx *ctx,
	t_list *redir_list
)
{
	t_redir_type	curr_type;
	t_redir			*curr_redir;
	t_list			*tmp;

	tmp = redir_list;
	while (tmp)
	{
		curr_redir = ft_ltor(tmp);
		curr_type = curr_redir->type;
		if (curr_type == REDIR_INPUT || curr_type == REDIR_HEREDOC)
		{
			if (check_redir_in(ctx, curr_redir) != RET_OK)
				return (RET_ERR);
		}
		else if (curr_type == REDIR_OUTPUT || curr_type == REDIR_APPEND)
		{
			if (check_redir_out(ctx, curr_redir) != RET_OK)
				return (RET_ERR);
		}
		tmp = tmp->next;
	}
	return (RET_OK);
}
