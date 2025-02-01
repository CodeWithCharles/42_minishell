/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 10:37:51 by onkeltag         ###   ########.fr       */
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
			return (n_option);
		}
	}
	return (n_option);
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
