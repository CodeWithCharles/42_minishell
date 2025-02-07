/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/07 20:26:50 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

static bool	_is_n_flag(
				char *arg,
				bool *n_option);

/**
 * @brief		Mimics the behavior of the Unix 'echo' command.
 *
 * @details 	This function will print the arguments to the standard output
 * 				followed by a newline. If the -n option is provided, the newline
 * 				will not be printed.
 *
 * @param ctx	The minishell context
 * @param args	The arguments
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/28 12:03:10
 */
int	ft_echo(
	t_minishell_ctx *ctx,
	char **args
)
{
	bool	n_option;

	(void)ctx;
	n_option = true;
	args++;
	while (*args)
	{
		if (!_is_n_flag(*args, &n_option))
			break ;
		++args;
	}
	while (*args)
	{
		fd_printf(STDOUT_FILENO, "%s", *args++);
		if (*args)
			fd_printf(STDOUT_FILENO, " ");
	}
	if (n_option)
		fd_printf(STDOUT_FILENO, "\n");
	return (RET_OK);
}

/**
 * @brief Check if the argument is the -n flag
 *
 * @details This function will check if the argument is the -n flag and set the
 * 			n_option flag accordingly.
 *
 * @param arg The argument to check
 * @param n_option The n_option flag
 *
 * @return bool true if the argument is the -n flag, false otherwise.
 *
 * @author jcheron
 * @date 2025/01/28 12:03:10
 */
static bool	_is_n_flag(
	char *arg,
	bool *n_option
)
{
	if (arg[0] != '-' || arg[1] == '\0')
		return (false);
	++arg;
	while (*arg)
	{
		if (*arg++ != 'n')
			return (false);
		*n_option = false;
	}
	return (true);
}
