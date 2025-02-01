/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:54:43 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/01 11:47:58 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_ft_split_count(char **split)
{
	int	count;

	if (!split)
		return (0);
	count = 0;
	while (split[count])
		count++;
	return (count);
}

t_cmd	*init_cmd_structs(
	char **cmds
)
{
	int		cmd_count;
	t_cmd	*cmd_structs;

	cmd_count = _ft_split_count(cmds);
	cmd_structs = malloc(sizeof(t_cmd) * (cmd_count + 1));
	if (!cmd_structs)
		return (ft_free_split(cmds), NULL);
	return (cmd_structs);
}

void	parse_single_cmd(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	char *cmd_str
)
{
	char	**args;
	int		k;

	args = spooq(cmd_str, ' ');
	if (!args)
		return ;
	parse_redir_input(ctx, cmd, &args);
	cmd->cmd_name = expand_variables_in_input(ctx, args[0]);
	args++;
	cmd->cmd_args = malloc(sizeof(char *) * (_ft_split_count(args) + 1));
	if (!cmd->cmd_args)
		return ;
	k = 0;
	while (args[k]
		&& ft_strcmp(args[k], ">") != 0 && ft_strcmp(args[k], ">>") != 0)
	{
		cmd->cmd_args[k] = expand_variables_in_input(ctx, args[k]);
		k++;
	}
	parse_redir_output(ctx, cmd, k, &args);
	cmd->cmd_args[k] = NULL;
}

void	parse_redir_input(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	char ***args
)
{
	int	i;

	i = 0;
	while ((*args)[i]
		&& (ft_strcmp((*args)[i], "<") == 0
		|| ft_strcmp((*args)[i], "<<") == 0))
	{
		if (ft_strcmp((*args)[i], "<") == 0)
			cmd->redir_in.type = REDIR_INPUT;
		else
			cmd->redir_in.type = REDIR_HEREDOC;
		(*args)++;
		cmd->redir_in.file = expand_variables_in_input(ctx, (*args)[0]);
		(*args)++;
	}
}

void	parse_redir_output(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	int k,
	char ***args
)
{
	while ((*args)[k]
		&& (ft_strcmp((*args)[k], ">") == 0
		|| ft_strcmp((*args)[k], ">>") == 0))
	{
		if (ft_strcmp((*args)[k], ">") == 0)
			cmd->redir_out.type = REDIR_OUTPUT;
		else
			cmd->redir_out.type = REDIR_APPEND;
		(*args)++;
		cmd->redir_out.file = expand_variables_in_input(ctx, (*args)[k]);
		if ((*args)[k + 1] == NULL)
			break ;
		(*args)++;
	}
}
