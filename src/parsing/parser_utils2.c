/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:11:44 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 08:05:54 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipe(
	t_cmd ***cmds,
	size_t *cmd_count,
	size_t *args_count
)
{
	add_cmd(cmds, cmd_count);
	if (!cmds)
		return ;
	*args_count = 0;
}

void	add_redirection(
	t_token **tmp,
	t_list **redir_list,
	int type
)
{
	ft_lstadd_back(redir_list, new_redir((*tmp)->next->value, type));
	*tmp = (*tmp)->next;
}

void	add_argument(
	t_cmd **current_cmd,
	t_token *tmp,
	size_t *args_count
)
{
	if (!(*current_cmd)->cmd_name)
		(*current_cmd)->cmd_name = tmp->value;
	(*current_cmd)->cmd_args = ft_realloc((*current_cmd)->cmd_args,
			sizeof(char *) * (*args_count + 2));
	if (!(*current_cmd)->cmd_args)
		return ;
	(*current_cmd)->cmd_args[(*args_count)++] = ft_strdup(tmp->value);
	(*current_cmd)->cmd_args[*args_count] = NULL;
}

t_list	*new_redir(
	char *file,
	t_redir_type type
)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->file = file;
	redir->type = type;
	return (ft_lstnew(redir));
}
