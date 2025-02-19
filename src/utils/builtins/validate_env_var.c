/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:53:13 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 16:04:42 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static int	_get_var_name_len(
				const char *var_name);

// Header implementations

int	validate_env_var_name(
	const char *var_name
)
{
	int	i;
	int	var_name_len;

	i = 0;
	var_name_len = _get_var_name_len(var_name);
	if (var_name_len < 1)
		return (RET_ERR);
	while (var_name[i] && var_name[i] != '='
		&& (ft_isalnum(var_name[i]) || var_name[i] == '_'))
		i++;
	return (!(i == var_name_len));
}

// Static implementations
static int	_get_var_name_len(
	const char *var_name
)
{
	int	i;

	i = 0;
	while (var_name[i] && var_name[i] != '=')
		i++;
	return (i);
}
