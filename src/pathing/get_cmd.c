/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:12 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 17:00:30 by cpoulain         ###   ########.fr       */
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

	if (!is_valid_builtin(cmd->argv[0]))
	{
		cmd_path = ft_which(cmd->argv[0]);
		if (cmd_path)
		{
			free(cmd->argv[0]);
			cmd->argv[0] = cmd_path;
		}
		else
		{
			print_arg_error(ctx, ERR_CMD_NOT_FOUND, cmd->argv[0]);
			cmd->fd_in = INVALID_FD;
			cmd->fd_out = INVALID_FD;
			cmd->exit_code = 127;
		}
	}
}
