/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:08:48 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/11 16:33:45 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_special_tokens(t_token **tokens, const char *input, size_t *i)
{
	if (input[*i] == '|')
	{
		add_token(tokens, new_token(PIPE, "|"));
		(*i)++;
		return (1);
	}
	if (input[*i] == '<')
		return (handle_redir_in(tokens, input, i));
	if (input[*i] == '>')
		return (handle_redir_out(tokens, input, i));
	return (0);
}

int	handle_var_expansion(t_token **tokens, const char *input, size_t *i)
{
	size_t	start;
	char	*var_name;
	char	*var_value;

	if (input[*i] == '$' && (ft_isalpha(input[*i + 1]) || input[*i + 1] == '_'))
	{
		start = ++(*i);
		while (ft_isalpha(input[*i]) || input[*i] == '_')
			(*i)++;
		var_name = ft_strndup(&input[start], *i - start);
		if (getenv(var_name))
			var_value = getenv(var_name);
		else
			var_value = "";
		add_token(tokens, new_token(WORD, var_value));
		free(var_name);
		return (1);
	}
	return (0);
}

int	handle_word_tokens(t_token **tokens, const char *input, size_t *i, int *in_quotes)
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
	add_token(tokens, new_token(WORD, word));
	return (free(word), 1);
}

t_token	*handle_unmatched_quotes(t_token *tokens)
{
	fd_printf(STDERR_FILENO, "Unmatched quote\n");
	free_tokens(tokens);
	return (NULL);
}
