/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/30 14:24:02 by jcheron          ###   ########.fr       */
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

bool	is_n_flag(
	char *arg,
	bool n_option
)
{
	if (arg[0] != '-' || arg[1] != '\0')
		return (false);
	++arg;
	while (*arg)
	{
		if (*arg++ != 'n')
			return (false);
		n_option = false;
	}
	return (true);
}

// void	ft_echo(
// 	t_minishell_ctx *ctx,
// 	char **args
// )
// {
// 	bool	n_option;

// 	(void)ctx;
// 	n_option = true;
// 	while (*args)
// 	{
// 		if (!is_n_flag(*args, &n_option))
// 			break ;
// 		++args;
// 	}
// 	while (*args)
// 	{
// 		fd_printf(STDOUT_FILENO, "%s", *args++);
// 		if (*args)
// 			fd_printf(STDOUT_FILENO, " ");
// 	}
// 	if (n_option)
// 		fd_printf(STDOUT_FILENO, "\n");
// }

static void	_print_arg(
	t_minishell_ctx *ctx,
	char *arg,
	bool in_single_quotes,
	bool in_double_quotes
)
{
	while (*arg)
	{
		if ((*arg == '\'' && !in_double_quotes)
			|| (*arg == '"' && !in_single_quotes))
		{
			++arg;
			continue ;
		}
		else if (!in_single_quotes && *arg == '$')
		{
			char	*env_name = get_env_name(arg + 1);
			if (env_name)
			{
				char	*env_value = get_env_value(ctx, env_name);
				if (env_value)
				{
					fd_printf(STDOUT_FILENO, "%s", env_value);
					free(env_value);
					arg += ft_strlen(env_name);
				}
				free(env_name);
			}
			else
				fd_printf(STDOUT_FILENO, "$");

		}
		else if (*arg == ' ')
			fd_printf(STDOUT_FILENO, " ");
		else
			fd_printf(STDOUT_FILENO, "%c", *arg);
		++arg;
	}
}

void	ft_echo(
	t_minishell_ctx *ctx,
	char **args
)
{
	bool	n_option;
	bool	in_single_quotes;
	bool	in_double_quotes;

	(void)ctx;
	n_option = false;
	in_single_quotes = false;
	in_double_quotes = false;
	while (*args && ft_strncmp(*args, "-n", 2) == 0)
	{
		++args;
		n_option = true;
	}
	while (*args)
	{
		if ((*args)[0] == '\'')
			in_single_quotes = !in_single_quotes;
		else if ((*args)[0] == '"')
			in_double_quotes = !in_double_quotes;
		_print_arg(ctx, *args, in_single_quotes, in_double_quotes);
		if (*++args)
			fd_printf(STDOUT_FILENO, " ");
	}
	if (!n_option)
		fd_printf(STDOUT_FILENO, "\n");
}
