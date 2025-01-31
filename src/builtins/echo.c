/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/31 13:04:49 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

static bool	_is_n_flag(
	char *arg,
	bool *n_option
)
{
	if (arg[0] != '-')
		return (false);
	++arg;
	while (*arg)
	{
		if (*arg++ != 'n')
		{
			n_option = false;
			return (false);
		}
	}
	return (true);
}

void	ft_echo(
	t_minishell_ctx *ctx,
	char **args
)
{
	bool	n_option;

	(void)ctx;
	n_option = true;
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
}
