/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:46 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/31 18:05:00 by jcheron          ###   ########.fr       */
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

t_cmd	*parse_commands(
	t_minishell_ctx *ctx,
	char *input
)
{
	char	**cmds;
	t_cmd	*cmd_structs;
	int		i;
	int		cmd_count;
	char	**args;
	int		j;

	(void)ctx;
	cmds = spooq(input, '|');
	if (!cmds)
		return (NULL);
	cmd_count = _ft_split_count(cmds);
	cmd_structs = malloc(sizeof(t_cmd) * (cmd_count + 1));
	if (!cmd_structs)
		return (ft_free_split(cmds), NULL);
	i = 0;
	while (i < cmd_count)
	{
		args = spooq(cmds[i], ' ');
		if (!args)
			continue ;
		while (ft_strcmp(args[0], "<") == 0 || ft_strcmp(args[0], "<<") == 0)
		{
			if (ft_strcmp(args[0], "<") == 0)
				cmd_structs[i].redir_in.type = REDIR_INPUT;
			else
				cmd_structs[i].redir_in.type = REDIR_HEREDOC;
			args++;
			cmd_structs[i].redir_in.file = expand_variables_in_input(ctx, args[0]);
			args++;
		}
		cmd_structs[i].cmd_name = expand_variables_in_input(ctx, args[0]);
		j = 0;
		cmd_structs[i].cmd_args = malloc(sizeof(char*) * (_ft_split_count(args) + 1)); // Allocation en fonction du nombre d'arguments
		if (!cmd_structs[i].cmd_args)
			return (ft_free_split(cmds), NULL);
		int k = 0;
		while (args[k] && ft_strcmp(args[k], ">") != 0 && ft_strcmp(args[k], ">>") != 0)
		{
			cmd_structs[i].cmd_args[k] = expand_variables_in_input(ctx, args[k]);
			k++;
		}
		if (ft_strcmp(args[k], ">") == 0)
		{
			cmd_structs[i].redir_out.type = REDIR_OUTPUT;
			cmd_structs[i].redir_out.file = expand_variables_in_input(ctx, args[k + 1]);
			k += 2;
		}
		else if (ft_strcmp(args[k], ">>") == 0)
		{
			cmd_structs[i].redir_out.type = REDIR_APPEND;
			cmd_structs[i].redir_out.file = expand_variables_in_input(ctx, args[k + 1]);
			k += 2;
		}
		cmd_structs[i].cmd_args[k] = NULL;
		i++;
	}
	cmd_structs[i].cmd_name = NULL;
	return (ft_free_split(cmds), cmd_structs);
}

