/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:03:55 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/11 16:25:07 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**add_cmd(t_cmd **cmds, t_cmd *current_cmd, size_t *cmd_count)
{
	t_cmd	**new_cmds;
	size_t	i;

	i = 0;
	new_cmds = realloc(cmds, sizeof(t_cmd *) * (*cmd_count + 2));
	if (!new_cmds)
	{
		printf("Error realloc\n");
		return (NULL);
	}
	while (i < *cmd_count)
	{
		new_cmds[i] = cmds[i];
		i++;
	}
	new_cmds[*cmd_count] = current_cmd;
	new_cmds[*cmd_count + 1] = NULL;
	(*cmd_count)++;
	return (new_cmds);
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
	return (tokens);
}

void	process_token(
	t_token **tmp,
	t_cmd **current_cmd,
	t_parser *parser
)
{
	if ((*tmp)->type == PIPE)
		*current_cmd = handle_pipe(parser->cmds, *current_cmd,
				&parser->cmd_count, &parser->args_count);
	else if ((*tmp)->type == REDIR_INPUT || (*tmp)->type == REDIR_HEREDOC)
		add_redirection(tmp, &(*current_cmd)->redir_in_list, (*tmp)->type);
	else if ((*tmp)->type == REDIR_OUTPUT || (*tmp)->type == REDIR_APPEND)
		add_redirection(tmp, &(*current_cmd)->redir_out_list, (*tmp)->type);
	else if ((*tmp)->type == WORD)
		add_argument(*current_cmd, *tmp, &parser->args_count);
	*tmp = (*tmp)->next;
}

t_cmd	**parse_tokens(
	t_token *tokens
)
{
	t_cmd		**cmds;
	t_cmd		*current_cmd;
	t_token		*tmp;
	t_parser	parser;

	cmds = NULL;
	current_cmd = new_cmd();
	if (!current_cmd)
		return (NULL);
	current_cmd->cmd_args = NULL;
	tmp = tokens;
	parser.cmds = cmds;
	parser.cmd_count = 0;
	parser.args_count = 0;
	while (tmp)
		process_token(&tmp, &current_cmd, &parser);
	if (current_cmd->cmd_name)
		cmds = add_cmd(parser.cmds, current_cmd, &parser.cmd_count);
	else
		free(current_cmd);
	return (cmds);
}
