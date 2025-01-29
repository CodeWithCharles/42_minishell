/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/29 16:49:02 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

/**
 * @brief		Returns the value of the environment variable with the provided name.
 *
 * @details 	This function searches the environment variables of the shell for
 * 				the variable with the provided name. If the variable is found, the
 * 				function returns the value of the variable. If the variable is not
 * 				found, the function returns NULL.
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

static bool	is_n_flag(
	char *arg,
	bool *n_option
)
{
	if (arg[0] != '-' || arg[1] != '\0')
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
		if (!is_n_flag(*args, &n_option))
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