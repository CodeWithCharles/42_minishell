/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:58:44 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 15:07:13 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static t_list	*handle_input(
					t_minishell_ctx *ctx,
					const char *input
					);

static int		check_invalid_pipe(
					const char *input
					);

// Header implementations

t_list	*tokenize(
	t_minishell_ctx *ctx,
	const char *input)
{
	if (check_invalid_pipe(input) != RET_OK)
		return (handle_parse_error(ctx, ERR_PARSE_ERROR_PIPE, NULL), NULL);
	return (handle_input(ctx, input));
}

t_list	*new_token(t_redir_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = ft_strdup(value);
	return (ft_lstnew(token));
}

void	free_token(void *token)
{
	t_token	*t;

	t = (t_token *)token;
	if (t)
	{
		if (t->value)
		{
			free(t->value);
			t->value = NULL;
		}
		free(t);
		t = NULL;
	}
}

// Static implementations

static t_list	*handle_input(
	t_minishell_ctx *ctx,
	const char *input
)
{
	t_list	*tokens;
	size_t	i;
	int		in_quotes;

	in_quotes = 0;
	i = 0;
	tokens = NULL;
	while (input[i])
	{
		if (ft_isspace(input[i]))
		{
			i++;
			continue ;
		}
		if (handle_special_tokens(&tokens, input, &i)
			//|| handle_var_expansion(&tokens, input, &i)
			|| handle_word_tokens(&tokens, input, &i, &in_quotes))
			continue ;
	}
	if (in_quotes)
		return (handle_parse_error(ctx, ERR_PARSE_ERROR_QUOTE, &tokens), NULL);
	return (tokens);
}

static int	check_invalid_pipe(
	const char *input
)
{
	int	i;

	i = 0;
	while (input[i] && ft_isspace(input[i]))
		i++;
	if (input[i] == '|')
		return (RET_ERR);
	i = ft_strlen(input) - 1;
	while (input[i] && ft_isspace(input[i]))
		i--;
	if (input[i] == '|')
		return (RET_ERR);
	return (RET_OK);
}
