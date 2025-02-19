/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:16 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 16:13:00 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	_is_numeric(
				char *arg);

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
	if (args && args[1])
	{
		if (!_is_numeric(args[1]))
		{
			print_arg_error(ctx, ERR_ARG_MUST_BE_INT, "exit");
			clean_exec_ctx(exec_ctx);
			exit(255);
		}
		if (args[2])
		{
			print_arg_error(ctx, ERR_TOO_MANY_ARGS, "exit");
			return ;
		}
		status = ft_atoi(args[1]);
	}
	clean_exec_ctx(exec_ctx);
	fd_printf(STDOUT_FILENO, "exit\n");
	exit(status);
}

static bool	_is_numeric(
	char *arg
)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}
