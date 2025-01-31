/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:35:08 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 17:14:14 by jcheron          ###   ########.fr       */
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
		return (ft_itoa(ft_last_exit_code(-1)));
	envp = *ft_envp(NULL);
	while (envp && !ft_env_varcmp((char *)envp->content, name))
		envp = envp->next;
	if (!envp)
		return (NULL);
	return (ft_strchr((char *)envp->content, '=') + 1);
}
