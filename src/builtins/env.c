/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:34:47 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/29 15:35:05 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'env' command.
 *
 * @details 	This function prints the environment variables of the shell to the
 * 				standard output.
 */
void	ft_env(
	t_minishell_ctx *ctx
)
{
	t_list	*env;

	env = ctx->envp;
	while (env)
	{
		ft_putstr_fd(((t_env_var *)env->content)->var_name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(((t_env_var *)env->content)->value, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}