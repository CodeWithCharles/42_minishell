/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:12 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 14:11:03 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

void	get_cmd(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	char	*cmd_path;

	if (!is_valid_builtin(cmd->cmd_name))
	{
		cmd_path = ft_which(cmd->cmd_name);
		free(cmd->cmd_name);
		if (cmd_path)
			cmd->cmd_name = cmd_path;
		else
		{
			print_arg_error(ctx, ERR_CMD_NOT_FOUND, cmd->cmd_name);
			cmd->fd_in = INVALID_FD;
			cmd->fd_out = INVALID_FD;
			cmd->cmd_name = NULL;
			cmd->exit_code = CODE_CMD_NOT_FOUND;
		}
	}
}
