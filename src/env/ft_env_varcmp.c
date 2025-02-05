/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_varcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:32:06 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/03 18:20:31 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

int	ft_env_varcmp(
	char *s1, char *s2
)
{
	size_t	n1len;
	size_t	n2len;

	n1len = 0;
	while (s1[n1len] && s1[n1len] != '=')
		++n1len;
	n2len = 0;
	while (s2[n2len] && s2[n2len] != '=')
		++n2len;
	return (n1len == n2len && ft_strncmp(s1, s2, ft_strchr(s1, '=') - s1) == 0);
}
