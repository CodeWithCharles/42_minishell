/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:31:24 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 17:01:50 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir_in(t_list **tokens, const char *input, size_t *i)
{
	if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
		{
			ft_lstadd_back(tokens, new_token(REDIR_HEREDOC, "<<"));
			(*i) += 2;
		}
		else
		{
			ft_lstadd_back(tokens, new_token(REDIR_INPUT, "<"));
			(*i)++;
		}
		return (1);
	}
	return (0);
}

int	handle_redir_out(t_list **tokens, const char *input, size_t *i)
{
	if (input[*i] == '>')
	{
		if (input[*i + 1] == '>')
		{
			ft_lstadd_back(tokens, new_token(REDIR_APPEND, ">>"));
			(*i) += 2;
		}
		else
		{
			ft_lstadd_back(tokens, new_token(REDIR_OUTPUT, ">"));
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
