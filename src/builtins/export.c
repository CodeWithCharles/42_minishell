/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:56:23 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 16:02:45 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(
	t_minishell_ctx *ctx,
	char **args
)
{
	int	i;

	if (!args[1])
		return (ft_env(ctx, args), RET_OK);
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			if (ft_strlen(args[i]) > 1
				&& validate_env_var_name(args[i]) == RET_OK)
			{
				trim_quotes(&args[i]);
				ft_setenv(args[i]);
			}
			else
				return (print_arg_error(ctx, ERR_BAD_ASSIGNMENT, "export"),
					RET_ERR);
		}
		i++;
	}
	return (RET_OK);
}
