/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:56:23 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/07 19:17:46 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(
	t_minishell_ctx *ctx,
	char **args
)
{
	int	i;

	if (!args[1])
		return (ft_env(ctx));
	i = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 1 && ft_strchr(args[i], '='))
			ft_setenv(args[i]);
		i++;
	}
}
