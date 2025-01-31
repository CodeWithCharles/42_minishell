/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:45:59 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 17:45:03 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_fds_if_open(t_cmd *cmd)
{
	if (cmd->fd_in != INVALID_FD)
	{
		close(cmd->fd_in);
		cmd->fd_in = INVALID_FD;
	}
	if (cmd->fd_out != INVALID_FD)
	{
		close(cmd->fd_out);
		cmd->fd_out = INVALID_FD;
	}
}

void	close_pipes(
	int cmd_count,
	int pipes[][2]
)
{
	int	i;

	i = 0;
	while (i < cmd_count - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		++i;
	}
}
