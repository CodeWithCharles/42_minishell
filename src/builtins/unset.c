/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:16:19 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 16:02:40 by cpoulain         ###   ########.fr       */
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
	while (args[i] && validate_env_var_name(args[i]) == RET_OK)
		ft_unsetenv(args[i++]);
	return (RET_OK);
}
