/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:36:03 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/30 17:27:27 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Returns the value of the environment variable
 * 				with the provided name.
 *
 * @details 	This function searches the environment variables of the shell for
 * 				the variable with the provided name. If the variable is found,
 * 				the function returns the value of the variable.
 * 				If the variable is not found, the function returns NULL.
 */
char	*get_env_name(
	char *arg
)
{
	char	*name;
	int		i;

	i = 0;
	if (!ft_isalpha(arg[i]) && arg[i] != '_')
		return (NULL);
	while (ft_isalnum(arg[i]) || arg[i] == '_')
		i++;
	name = ft_substr(arg, 0, i);
	return (name);
}

/**
 * @brief		Returns the value of the environment variable
 * 				with the provided name.
 *
 * @details 	This function searches the environment variables of the shell for
 * 				the variable with the provided name. If the variable is found,
 * 				the function returns the value of the variable.
 * 				If the variable is not found, the function returns NULL.
 */
// char	*get_env_value(
// 	t_minishell_ctx *ctx,
// 	char *name
// )
// {
// 	t_list		*env;
// 	t_env_var	*var;

// 	if (!ctx || !ctx->envp || !name)
// 		return (ft_strdup(""));
// 	env = ctx->envp;
// 	while (env)
// 	{
// 		var = ft_getenv(get_env_name);
// 		if (var && var->var_name && !ft_strcmp(var->var_name, name))
// 		{
// 			if (var->value)
// 				return (ft_strdup(var->value));
// 			else
// 				return (ft_strdup(""));
// 		}
// 		env = env->next;
// 	}
// 	return (ft_strdup(""));
// }
