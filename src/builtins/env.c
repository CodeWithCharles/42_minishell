/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:34:47 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/07 20:30:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'env' command.
 *
 * @details 	This function prints the environment variables
 * 				of the shell to the standard output.
 *
 * @param ctx	The minishell context
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/29 15:34:47
 */
int	ft_env(
	t_minishell_ctx *ctx,
	char **args
)
{
	t_list	*env;

	if (args[1])
		return (print_arg_error(ctx, ERR_TOO_MANY_ARGS, args[0]), RET_ERR);
	env = *ft_envp(NULL);
	while (env)
	{
		fd_printf(STDOUT_FILENO, "%s\n", (char *)env->content);
		env = env->next;
	}
	return (RET_OK);
}
