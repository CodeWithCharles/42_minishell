/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:03:55 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 13:53:17 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd(t_cmd ***cmds, size_t *cmd_count)
{
	*cmds = ft_realloc(*cmds, sizeof(t_cmd *) * (*cmd_count + 2));
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

t_token	*tokenize(
	const char *input)
{
	t_token	*tokens;
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
		return (handle_unmatched_quotes(tokens));
	// free((char *)input);
	return (tokens);
}

void	process_token(
	t_token **tmp,
	t_cmd ***cmds,
	t_parser *parser
)
{
	if ((*tmp)->type == PIPE)
		handle_pipe(&parser->cmds, &parser->cmd_count, &parser->args_count);
	else if ((*tmp)->type == REDIR_INPUT || (*tmp)->type == REDIR_HEREDOC)
		add_redirection(tmp, &((*cmds)[parser->cmd_count - 1])->redir_in_list,
			(*tmp)->type);
	else if ((*tmp)->type == REDIR_OUTPUT || (*tmp)->type == REDIR_APPEND)
		add_redirection(tmp, &((*cmds)[parser->cmd_count - 1])->redir_out_list,
			(*tmp)->type);
	else if ((*tmp)->type == WORD)
		add_argument(&((*cmds)[parser->cmd_count - 1]),
			*tmp, &parser->args_count);
	*tmp = (*tmp)->next;
}

t_cmd	**parse_tokens(
	t_token *tokens
)
{
	t_token		*tmp;
	t_parser	parser;

	tmp = tokens;
	parser.cmd_count = 0;
	parser.cmds = malloc(sizeof(t_cmd *) * (parser.cmd_count + 2));
	parser.cmds[0] = new_cmd();
	parser.cmds[1] = NULL;
	parser.cmd_count++;
	parser.args_count = 0;
	while (tmp)
		process_token(&tmp, &parser.cmds, &parser);
	return (parser.cmds);
}
