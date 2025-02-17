/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:12 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 17:51:59 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Static prototypes

static void	_handle_not_found(
				t_minishell_ctx *ctx,
				t_cmd *cmd);

// Header implementations

void	get_cmd(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	char	*cmd_path;

	if (ft_strchr(cmd->cmd_name, '/') && access(cmd->cmd_name, X_OK) == -1)
		_handle_not_found(ctx, cmd);
	else if (!is_valid_builtin(cmd->cmd_name))
	{
		cmd_path = ft_which(cmd->cmd_name);
		if (cmd_path)
		{
			free(cmd->cmd_name);
			cmd->cmd_name = NULL;
			cmd->cmd_name = cmd_path;
		}
		else
		{
			_handle_not_found(ctx, cmd);
			free(cmd_path);
		}
	}
}

// Static implementations

static void	_handle_not_found(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	print_arg_error(ctx, ERR_CMD_NOT_FOUND, cmd->cmd_name);
	free(cmd->cmd_name);
	cmd->cmd_name = NULL;
	cmd->fd_in = INVALID_FD;
	cmd->fd_out = INVALID_FD;
	cmd->exit_code = CODE_CMD_NOT_FOUND;
}
