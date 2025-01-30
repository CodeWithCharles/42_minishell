/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/30 17:30:04 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

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

static void	_handle_env_var(
			t_minishell_ctx *ctx,
			char **arg
)
{
	char	*env_name;
	char	*env_value;

	(void)ctx;
	if ((*arg)[1] == '?')
	{
		fd_printf(STDOUT_FILENO, "%d", ft_last_exit_code(-1));
		(*arg) += 2;
		return ;
	}
	env_name = get_env_name(*arg + 1);
	if (!env_name)
		fd_printf(STDOUT_FILENO, "$");
	else
	{
		env_value = ft_getenv(env_name);
		if (!env_value)
			env_value = ft_strdup("");
		if (env_value)
		{
			fd_printf(STDOUT_FILENO, "%s", env_value);
			(*arg) += ft_strlen(env_name);
		}
	}
}

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
			_handle_env_var(ctx, &arg);
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
