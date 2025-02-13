/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:31:24 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 10:39:56 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir_in(t_token **tokens, const char *input, size_t *i)
{
	if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
		{
			add_token(tokens, new_token(REDIR_HEREDOC, "<<"));
			(*i) += 2;
		}
		else
		{
			add_token(tokens, new_token(REDIR_INPUT, "<"));
			(*i)++;
		}
		return (1);
	}
	return (0);
}

int	handle_redir_out(t_token **tokens, const char *input, size_t *i)
{
	if (input[*i] == '>')
	{
		if (input[*i + 1] == '>')
		{
			add_token(tokens, new_token(REDIR_APPEND, ">>"));
			(*i) += 2;
		}
		else
		{
			add_token(tokens, new_token(REDIR_OUTPUT, ">"));
			(*i)++;
		}
		return (1);
	}
	return (0);
}

char	*trim_quotes(const char *str)
{
	size_t		start;
	size_t		end;
	char		*new_str;

	start = 0;
	end = ft_strlen(str);
	if (str[start] == '\'' || str[start] == '\"')
		start++;
	if (str[end - 1] == '\'' || str[end - 1] == '\"')
		end--;
	new_str = ft_strndup(&str[start], end - start);
	return (new_str);
}
