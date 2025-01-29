/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:12 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 12:50:30 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

void	get_cmd(
	t_cmd *cmd,
	t_minishell_ctx *ctx
)
{
	char	*cmd_path;

	if (!valid_builtin(cmd->argv[0]))
	{
		cmd_path = ft_which(cmd->argv[0], envp);
		if (cmd_path)
		{
			free(cmd->argv[0]);
			cmd->argv[0] = cmd_path;
		}
		else
		{
			print_gen_error(ctx, ERR_CMD_NOT_FOUND, cmd->argv[0]);
			cmd->fd_in = INVALID_FD;
			cmd->fd_out = INVALID_FD;
			cmd->exit_code = 127;
		}
	}
}
