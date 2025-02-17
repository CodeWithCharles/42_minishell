/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:14:53 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 13:15:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Header implementations

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd_name = NULL;
	cmd->cmd_args = NULL;
	cmd->redir_in_list = NULL;
	cmd->redir_out_list = NULL;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->exit_code = 0;
	return (cmd);
}

void	add_cmd(t_cmd ***cmds, size_t *cmd_count)
{
	if (*cmds)
		*cmds = ft_add_one_to_tab(*cmds, sizeof(t_cmd *) * (*cmd_count + 2));
	else
		*cmds = malloc(sizeof(t_cmd *) * (*cmd_count + 2));
	if (!cmds)
		return ((void)ft_printf("Error realloc\n"));
	(*cmds)[*cmd_count] = new_cmd();
	(*cmds)[*cmd_count + 1] = NULL;
	(*cmd_count)++;
}
