/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_specializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:10:02 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 15:05:45 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static int	handle_redir_in(
				t_list **tokens,
				const char *input,
				size_t *i
				);

static int	handle_redir_out(
				t_list **tokens,
				const char *input,
				size_t *i
				);

// Header implementations

int	handle_special_tokens(
	t_list **tokens,
	const char *input,
	size_t *i
)
{
	if (input[*i] == '|')
	{
		ft_lstadd_back(tokens, new_token(PIPE, "|"));
		(*i)++;
		return (1);
	}
	if (input[*i] == '<')
		return (handle_redir_in(tokens, input, i));
	if (input[*i] == '>')
		return (handle_redir_out(tokens, input, i));
	return (0);
}

// Static implementations

static int	handle_redir_in(
	t_list **tokens,
	const char *input,
	size_t *i
)
{
	if (input[*i] == '<' && input[*i + 1])
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
	else if (input[*i] == '<')
		(*i)++;
	return (0);
}

static int	handle_redir_out(
	t_list **tokens,
	const char *input,
	size_t *i
)
{
	if (input[*i] == '>' && input[*i + 1])
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
	else if (input[*i] == '>')
		(*i)++;
	return (0);
}
