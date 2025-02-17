/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastredir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:43:07 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 16:57:28 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir	*ft_lastredir(
	t_list *redir_list,
	t_redir_type type
)
{
	t_redir	*last_found;
	t_list	*tmp;
	t_redir	*curr_redir;

	last_found = NULL;
	tmp = redir_list;
	while (tmp)
	{
		curr_redir = ft_ltor(tmp);
		if (type == REDIR_INPUT && (curr_redir->type == type
				|| curr_redir->type == REDIR_HEREDOC))
			last_found = curr_redir;
		if (type == REDIR_OUTPUT && (curr_redir->type == type
				|| curr_redir->type == REDIR_APPEND))
			last_found = curr_redir;
		tmp = tmp->next;
	}
	return (last_found);
}
