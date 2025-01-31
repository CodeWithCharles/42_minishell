/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:02:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/31 12:24:37 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*expand_variables_in_input(
			t_minishell_ctx *ctx,
			char			*input
)
{
	char	*expanded;
	int		i;
	int		j;
	int		in_simple_quote;
	int		in_double_quote;
	int		start;

	(void)ctx;
	expanded = malloc(sizeof(char) * (ft_strlen(input) + 1));
	if (!expanded)
		return (NULL);
	i = 0;
	j = 0;
	in_simple_quote = 0;
	in_double_quote = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' && !in_double_quote)
		{
			in_simple_quote = !in_simple_quote;
			i++;
		}
		else if (input[i] == '"' && !in_simple_quote)
		{
			in_double_quote = !in_double_quote;
			i++;
		}
		else if (input[i] == '$' && !in_simple_quote)
		{
			i++;
			start = i;
			while (ft_isalnum(input[i]) || input[i] == '_')
				i++;
			int len = i - start;
			if (ft_getenv(ft_substr(input, start, len)))
			{
				ft_strlcpy(expanded + j, ft_getenv(ft_substr(input, start, len)), ft_strlen(ft_getenv(ft_substr(input, start, len))) + 1);
				j += ft_strlen(ft_getenv(ft_substr(input, start, len)));
			}
			else
			{
			}
		}
		else
			expanded[j++] = input[i++];
	}
	expanded[j] = '\0';
	return (expanded);
}
