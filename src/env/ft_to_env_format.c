/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_env_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:45:14 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/07 18:52:06 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_to_env_format(
	const char *var_name,
	const char *var_value
)
{
	char	*ret;

	ret = ft_strdup(var_name);
	if (!ret)
		return (NULL);
	ft_strcat(&ret, "=");
	if (!ret)
		return (NULL);
	ft_strcat(&ret, var_value);
	return (ret);
}
