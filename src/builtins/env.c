/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:34:47 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/01 14:58:10 by onkeltag         ###   ########.fr       */
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
void	ft_env(
	t_minishell_ctx *ctx
)
{
	t_list	*env;

	(void)ctx;
	env = *ft_envp(NULL);
	while (env)
	{
		fd_printf(STDOUT_FILENO, "%s\n", (char *)env->content);
		env = env->next;
	}
}
