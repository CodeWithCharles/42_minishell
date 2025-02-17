/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:08:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 13:27:45 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static void	expand_variable(
				t_list **tokens,
				const char *input,
				size_t *i
				);

// Header implementations

int	handle_var_expansion(
	t_list **tokens,
	const char *input,
	size_t *i
	)
{
	char	*var_value;

	if (input[*i] == '$' && input[*i + 1] == '?')
	{
		var_value = ft_itoa(ft_last_exit_code(-1));
		ft_lstadd_back(tokens, new_token(WORD, var_value));
		(*i) += 2;
		return (free(var_value), 1);
	}
	if (input[*i] == '$' && (ft_isalpha(input[*i + 1]) || input[*i + 1] == '_'))
		return (expand_variable(tokens, input, i), 1);
	return (0);
}

// Static implementations

static void	expand_variable(
	t_list **tokens,
	const char *input,
	size_t *i
)
{
	size_t	start;
	char	*var_value;
	char	*var_name;

	start = ++(*i);
	while (ft_isalpha(input[*i]) || input[*i] == '_')
		(*i)++;
	var_name = ft_strndup(&input[start], *i - start);
	var_value = ft_getenv(var_name);
	if (!var_value)
		var_value = "";
	ft_lstadd_back(tokens, new_token(WORD, var_value));
	free(var_name);
	if (var_value)
		free(var_value);
}
