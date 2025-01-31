/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:23:30 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 15:49:27 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

t_list	**ft_envp(
	char **envp
)
{
	static t_list	*saved_envp = NULL;
	size_t			i;

	if (envp == NULL)
		return (&saved_envp);
	i = 0;
	while (envp[i])
		ft_lstadd_back(&saved_envp, ft_lstnew(ft_strdup(envp[i++])));
	return (NULL);
}
