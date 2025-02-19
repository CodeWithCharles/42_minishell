/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:16:19 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 16:18:25 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(
	t_minishell_ctx *ctx,
	char **args
)
{
	int		i;

	(void)ctx;
	i = 1;
	while (args[i])
	{
		if (validate_env_var_name(args[i]) != RET_OK)
		{
			print_cmd_errno(ctx, ERR_INVALID_PRM_NAME, "unset", args[i]);
			return (RET_ERR);
		}
		else
			ft_unsetenv(args[i++]);
	}
	return (RET_OK);
}
