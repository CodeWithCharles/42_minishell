/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_worder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:10:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 13:10:42 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_word_tokens(
	t_list **tokens,
	const char *input,
	size_t *i,
	int *in_quotes
)
{
	size_t	start;
	char	quote_char;
	char	*word;

	start = *i;
	quote_char = '\0';
	while (input[*i] && (*in_quotes || (!ft_isspace(input[*i])
				&& input[*i] != '|' && input[*i] != '>' && input[*i] != '<')))
	{
		if ((input[*i] == '"' || input[*i] == '\'')
			&& (*i == start || input[*i - 1] != '\\'))
		{
			if (!(*in_quotes))
			{
				*in_quotes = 1;
				quote_char = input[*i];
			}
			else if (quote_char == input[*i])
				*in_quotes = 0;
		}
		(*i)++;
	}
	word = ft_strndup(&input[start], *i - start);
	ft_lstadd_back(tokens, new_token(WORD, word));
	return (free(word), 1);
}
