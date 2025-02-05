/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:16 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/05 11:03:55 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'exit' command.
 *
 * @details 	This function exits the shell with the status provided as the
 * 				first argument. If no argument is provided, the shell exits
 * 				with the status 0.
 *
 * @param ctx	The minishell context
 * @param args	The arguments
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/28 13:10:16
 */

void	ft_exit(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	char **args
)
{
	int		status;

	status = 0;
	ft_lstclear(ft_envp(NULL), free);
	if (args[0])
	{
		if (!ft_isdigit(args[0][0]))
		{
			print_arg_error(ctx, ERR_ARG_MUST_BE_INT, "exit");
			clean_exec_ctx(exec_ctx);
			exit(255);
		}
		status = ft_atoi(args[0]);
	}
	clean_exec_ctx(exec_ctx);
	exit(status);
}
