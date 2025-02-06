/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:54:43 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/06 10:02:20 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Count the number of elements in a split
 *
 * @details This function will count the number of elements in a split
 *
 * @param split The split to count
 *
 * @return int The number of elements in the split
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
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

/**
 * @brief Initialize the command structures
 *
 * @details This function will initialize the command structures
 *
 * @param cmds The commands to initialize
 *
 * @return t_cmd* The command structures
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
t_cmd	*init_cmd_structs(
	char **cmds
)
{
	int		cmd_count;
	t_cmd	*cmd_structs;

	cmd_count = _ft_split_count(cmds);
	cmd_structs = malloc(sizeof(t_cmd) * (cmd_count + 1));
	if (!cmd_structs)
		return (ft_free_split(&cmds), NULL);
	ft_bzero(cmd_structs, sizeof(t_cmd) * (cmd_count + 1));
	return (cmd_structs);
}

/**
 * @brief Parse a single command
 *
 * @details This function will parse a single command and fill the command
 * 			structure with the command name, arguments and redirections.
 *
 * @param ctx The minishell context
 * @param cmd The command structure
 *
 * @return t_cmd* The command structure containing the parsed command
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
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
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	k = parse_redir_input(ctx, cmd, &args);
	cmd->cmd_name = expand_variables_in_input(ctx, args[k]);
	cmd->cmd_args = malloc(sizeof(char *) * (_ft_split_count(args) + 1));
	if (!cmd->cmd_args)
		return ;
	while (args[k]
		&& (ft_strcmp(args[k], ">") != 0 && ft_strcmp(args[k], ">>") != 0))
	{
		cmd->cmd_args[k] = expand_variables_in_input(ctx, args[k]);
		k++;
	}
	parse_redir_output(ctx, cmd, k, &args);
	cmd->cmd_args[k] = NULL;
	if (args)
		ft_free_split(&args);
}

/**
 * @brief Parse the input redirection
 *
 * @details This function will parse the input redirection setting the command
 * 			structure with the input redirection type and file.
 *
 * @param ctx The minishell context
 * @param cmd The command structure
 * @param args The arguments
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
int	parse_redir_input(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	char ***args
)
{
	int		i;
	char	**arg_list;

	i = 0;
	arg_list = *args;
	if (ft_strcmp(arg_list[i], "<") != 0
		&& ft_strcmp(arg_list[i], "<<") != 0)
	{
		cmd->redir_in.type = REDIR_NONE;
		cmd->redir_in.file = NULL;
		return (0);
	}
	while (arg_list[i]
		&& (ft_strcmp(arg_list[i], "<") == 0
			|| ft_strcmp(arg_list[i], "<<") == 0))
	{
		if (ft_strcmp(arg_list[i], "<") == 0)
			cmd->redir_in.type = REDIR_INPUT;
		else
			cmd->redir_in.type = REDIR_HEREDOC;
		i++;
		cmd->redir_in.file = expand_variables_in_input(ctx, arg_list[i]);
		i++;
	}
	return (i);
}

/**
 * @brief Parse the output redirection
 *
 * @details This function will parse the output redirection setting the command
 * 			structure with the output redirection type and file.
 *
 * @param ctx The minishell context
 * @param cmd The command structure
 * @param k The index
 * @param args The arguments
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
void	parse_redir_output(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	int k,
	char ***args
)
{
	char	**arg_list;

	arg_list = *args;
	if (!arg_list[k] || (ft_strcmp(arg_list[k], ">") != 0
			&& ft_strcmp(arg_list[k], ">>") != 0))
	{
		cmd->redir_out.type = REDIR_NONE;
		cmd->redir_out.file = NULL;
		return ;
	}
	while (arg_list[k]
		&& (ft_strcmp(arg_list[k], ">") == 0
			|| ft_strcmp(arg_list[k], ">>") == 0))
	{
		if (ft_strcmp(arg_list[k], ">") == 0)
			cmd->redir_out.type = REDIR_OUTPUT;
		else
			cmd->redir_out.type = REDIR_APPEND;
		k++;
		cmd->redir_out.file = expand_variables_in_input(ctx, arg_list[k]);
		k++;
	}
}
