/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:39 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/06 12:12:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unsetenv(
	char *name
)
{
	t_list	**envp;

	envp = ft_envp(NULL);
	while (*envp && !ft_env_varcmp((char *)(*envp)->content, name))
		envp = &(*envp)->next;
	ft_lstremove(envp, free);
}
