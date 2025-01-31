/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:32:31 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 13:53:32 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_envp_tab(char ***envp_tab)
{
	t_list	*envp_list;
	size_t	size;
	size_t	i;

	i = 0;
	envp_list = *ft_envp(NULL);
	size = ft_lstsize(envp_list);
	*envp_tab = malloc((size + 1) * sizeof(void *));
	if (!*envp_tab)
		return (RET_ERR);
	while (envp_list)
	{
		(*envp_tab)[i++] = envp_list->content;
		envp_list = envp_list->next;
	}
	(*envp_tab)[i] = NULL;
	return (RET_OK);
}
