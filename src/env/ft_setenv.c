/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:43:33 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 15:49:50 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

void	ft_setenv(
	char *variable
)
{
	t_list	*envp;
	int		replaced;

	envp = *ft_envp(NULL);
	replaced = 0;
	while (envp && !replaced)
	{
		if (ft_env_varcmp((char *)envp->content, variable))
		{
			replaced = 1;
			free(envp->content);
			envp->content = ft_strdup(variable);
		}
		envp = envp->next;
	}
	if (!replaced)
		ft_lstadd_back(ft_envp(NULL), ft_lstnew(ft_strdup(variable)));
}
