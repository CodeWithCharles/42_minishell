/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:04:21 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 12:50:26 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static void	process_token(
				t_list **tmp,
				t_cmd ***cmds,
				t_parser *parser);

static void	add_argument(
				t_cmd **current_cmd,
				t_token **tmp,
				size_t *args_count);

static void	handle_pipe(
				t_cmd ***cmds,
				size_t *cmd_count,
				size_t *args_count);

// Header implementations

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

// Static implementations

static void	process_token(
	t_list **tmp,
	t_cmd ***cmds,
	t_parser *parser
)
{
	t_token	*token;

	token = ft_ltotoken(*tmp);
	if (token->type == PIPE)
		handle_pipe(&parser->cmds, &parser->cmd_count, &parser->args_count);
	else if (token->type == REDIR_INPUT || token->type == REDIR_HEREDOC
		|| token->type == REDIR_APPEND || token->type == REDIR_OUTPUT)
		add_redirection(tmp, &((*cmds)[parser->cmd_count - 1])->redir_list,
			token->type);
	else if (token->type == WORD)
		add_argument(&((*cmds)[parser->cmd_count - 1]),
			&token, &parser->args_count);
	*tmp = (*tmp)->next;
}

static void	add_argument(
	t_cmd **current_cmd,
	t_token **tmp,
	size_t *args_count
)
{
	if (_in_quotes((*tmp)->value))
		trim_quotes(&(*tmp)->value);
	else
		expand_variable(&(*tmp)->value);
	if (!(*current_cmd)->cmd_name)
		(*current_cmd)->cmd_name = ft_strdup((*tmp)->value);
	(*current_cmd)->cmd_args = ft_add_one_to_tab((*current_cmd)->cmd_args,
			sizeof(char *) * (*args_count + 2));
	if (!(*current_cmd)->cmd_args)
		return ;
	(*current_cmd)->cmd_args[(*args_count)++] = ft_strdup((*tmp)->value);
	(*current_cmd)->cmd_args[*args_count] = NULL;
}

static void	handle_pipe(
	t_cmd ***cmds,
	size_t *cmd_count,
	size_t *args_count
)
{
	add_cmd(cmds, cmd_count);
	if (!cmds)
		return ;
	*args_count = 0;
}
