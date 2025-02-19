/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:35:08 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 12:12:04 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

char	*ft_getenv(
	char *name
)
{
	t_list	*envp;

	if (ft_strcmp(name, "?") == 0)
		return (ft_itoa(g_signal));
	envp = *ft_envp(NULL);
	while (envp && !ft_env_varcmp((char *)envp->content, name))
		envp = envp->next;
	if (!envp)
		return (NULL);
	return (ft_strdup(ft_strchr((char *)envp->content, '=') + 1));
}
