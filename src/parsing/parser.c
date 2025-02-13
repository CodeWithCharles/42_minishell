/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:03:55 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 17:42:15 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd(t_cmd ***cmds, size_t *cmd_count)
{
	if (*cmds)
		*cmds = ft_realloc(*cmds, sizeof(t_cmd *) * (*cmd_count + 2));
	else
		*cmds = malloc(sizeof(t_cmd *) * (*cmd_count + 2));
	if (!cmds)
		return ((void)ft_printf("Error realloc\n"));
	(*cmds)[*cmd_count] = new_cmd();
	(*cmds)[*cmd_count + 1] = NULL;
	(*cmd_count)++;
}

char	*args_to_string(
	int ac,
	char **args
)
{
	int		i;
	int		len;
	char	*str;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(args[i]);
		i++;
	}
	str = malloc(len + ac - 2 + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(&str, args[i]);
		if (i < ac - 1)
			ft_strcat(&str, " ");
		i++;
	}
	return (str);
}

t_list	*tokenize(
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
		return (handle_unmatched_quotes(&tokens), NULL);
	// free((char *)input);
	return (tokens);
}

void	process_token(
	t_list **tmp,
	t_cmd ***cmds,
	t_parser *parser
)
{
	t_token	*token;

	token = ft_ltotoken(*tmp);
	if (token->type == PIPE)
		handle_pipe(&parser->cmds, &parser->cmd_count, &parser->args_count);
	else if (token->type == REDIR_INPUT || token->type == REDIR_HEREDOC)
		add_redirection(tmp, &((*cmds)[parser->cmd_count - 1])->redir_in_list,
			token->type);
	else if (token->type == REDIR_OUTPUT || token->type == REDIR_APPEND)
		add_redirection(tmp, &((*cmds)[parser->cmd_count - 1])->redir_out_list,
			token->type);
	else if (token->type == WORD)
		add_argument(&((*cmds)[parser->cmd_count - 1]),
			&token, &parser->args_count);
	*tmp = (*tmp)->next;
}

t_cmd	**parse_tokens(
	t_list *tokens
)
{
	t_list		*tmp;
	t_parser	parser;

	tmp = tokens;
	parser.cmd_count = 0;
	parser.cmds = NULL;
	add_cmd(&parser.cmds, &parser.cmd_count);
	parser.args_count = 0;
	while (tmp)
		process_token(&tmp, &parser.cmds, &parser);
	return (parser.cmds);
}
