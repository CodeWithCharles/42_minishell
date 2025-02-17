/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:58:44 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 13:12:08 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_list	*tokenize(
	t_minishell_ctx *ctx,
	const char *input)
{
	t_list	*tokens;
	size_t	i;
	int		in_quotes;

	tokens = NULL;
	i = 0;
	in_quotes = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
		{
			i++;
			continue ;
		}
		if (handle_special_tokens(&tokens, input, &i))
			continue ;
		if (handle_var_expansion(&tokens, input, &i))
			continue ;
		if (handle_word_tokens(&tokens, input, &i, &in_quotes))
			continue ;
	}
	if (in_quotes)
		return (handle_parse_error(ctx, ERR_PARSE_ERROR_QUOTE, &tokens), NULL);
	return (tokens);
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
