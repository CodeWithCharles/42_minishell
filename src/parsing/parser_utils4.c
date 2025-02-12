/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:31:24 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/11 16:31:29 by jcheron          ###   ########.fr       */
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
