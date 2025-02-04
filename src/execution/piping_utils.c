/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:45:59 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/04 15:21:35 by cpoulain         ###   ########.fr       */
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

void	close_pipe(
	int pipe[2]
)
{
	if (pipe[0] > 0)
		close(pipe[0]);
	if (pipe[1] > 0)
		close(pipe[1]);
}

void	close_pipes(
	int cmd_count,
	int pipes[][2]
)
{
	int	i;

	i = 0;
	while (i < cmd_count)
		close_pipe(pipes[i++]);
}
