/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:02:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/03 10:16:33 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quotes(
			char c,
			int *in_simple_quote,
			int *in_double_quote);

int		expand_variable(
			char	*input,
			int		*i,
			char	*expanded,
			int		*j);

int	process_char(
	char *input,
	char *expanded,
	t_expand_vars *vars
)
{
	handle_quotes(input[vars->i],
		&vars->in_simple_quote, &vars->in_double_quote);
	if (input[vars->i] == '$' && !vars->in_simple_quote)
	{
		vars->i++;
		if (expand_variable(input, &vars->i, expanded, &vars->j) == -1)
			return (-1);
	}
	else
		expanded[vars->j++] = input[vars->i++];
	return (0);
}

char	*handle_env_var(
			t_minishell_ctx *ctx,
			char **arg
)
{
	char	*env_name;
	char	*env_value;

	(void)ctx;
	if ((*arg)[1] == '?')
	{
		(*arg) += 2;
		return (ft_itoa(ft_last_exit_code(-1)));
	}
	env_name = get_env_name(*arg);
	if (!env_name)
	{
		*arg += 1;
		return (ft_strdup("$"));
	}
	env_value = ft_getenv(env_name);
	if (!env_value)
		env_value = ft_strdup("");
	*arg += ft_strlen(env_name) + 1;
	return (env_value);
}

int	expand_variable(
	char	*input,
	int		*i,
	char	*expanded,
	int		*j
)
{
	int		start;
	int		len;
	char	*var_name;
	char	*var_value;

	if (!ft_isalnum(input[*i]) && input[*i] != '_')
	{
		expanded[(*j)++] = '$';
		return (0);
	}
	start = *i;
	while (ft_isalnum(input[*i]) || input[*i] == '_')
		(*i)++;
	len = *i - start;
	var_name = ft_substr(input, start, len);
	if (!var_name)
		return (-1);
	var_value = ft_getenv(var_name);
	free(var_name);
	if (var_value)
	{
		ft_strlcpy(expanded + *j, var_value, ft_strlen(var_value) + 1);
		*j += ft_strlen(var_value);
	}
	return (0);
}

void	handle_quotes(
	char c,
	int *in_simple_quote,
	int *in_double_quote
)
{
	if (c == '\'' && !*in_double_quote)
		*in_simple_quote = !*in_simple_quote;
	else if (c == '"' && !*in_simple_quote)
		*in_double_quote = !*in_double_quote;
}

char	*expand_variables_in_input(
	t_minishell_ctx *ctx,
	char			*input
)
{
	char			*expanded;
	t_expand_vars	vars;

	(void)ctx;
	expanded = malloc(sizeof(char) * (ft_strlen(input) + 1));
	if (!expanded)
		return (NULL);
	init_expand_vars(&vars);
	while (input[vars.i])
	{
		if (process_char(input, expanded, &vars) == -1)
			return (free(expanded), NULL);
	}
	expanded[vars.j] = '\0';
	return (expanded);
}
