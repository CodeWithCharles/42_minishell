/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:36:03 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/29 15:46:05 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Returns the value of the environment variable with the provided name.
 *
 * @details 	This function searches the environment variables of the shell for
 * 				the variable with the provided name. If the variable is found, the
 * 				function returns the value of the variable. If the variable is not
 * 				found, the function returns NULL.
 */
char	*get_env_value(
	t_minishell_ctx *ctx,
	char *name
)
{
	t_list		*env;
	t_env_var	*var;

	if (!ctx || !ctx->envp || !name)
		return (ft_strdup(""));
	env = ctx->envp;
	while (env)
	{
		var = (t_env_var *)env->content;
		if (var && var->var_name && !ft_strcmp(var->var_name, name))
			{
				if (var->value)
					return (ft_strdup(var->value));
				else
					return (ft_strdup(""));
			}
		env = env->next;
	}
	return (ft_strdup(""));
}
