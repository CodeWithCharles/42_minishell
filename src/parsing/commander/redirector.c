/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:01:21 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 16:38:33 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_list	*new_redir(
	char *file,
	t_redir_type type
)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->file = ft_strdup(file);
	trim_quotes(&redir->file);
	redir->type = type;
	return (ft_lstnew(redir));
}

void	add_redirection(
	t_list **tmp,
	t_list **redir_list,
	int type
)
{
	ft_lstadd_back(redir_list,
		new_redir(((t_token *)((*tmp)->next)->content)->value, type));
	*tmp = (*tmp)->next;
}
