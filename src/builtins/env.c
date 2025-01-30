/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:34:47 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/30 17:18:45 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'env' command.
 *
 * @details 	This function prints the environment variables
 * 				of the shell to the standard output.
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
