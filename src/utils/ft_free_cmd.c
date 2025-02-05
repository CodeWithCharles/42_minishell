/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:44:50 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/05 17:37:32 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_cmd(
	t_cmd *cmd
)
{
	if (!cmd)
		return ;
	if (cmd->cmd_name)
		free(cmd->cmd_name);
	if (cmd->cmd_args)
		ft_free_split(cmd->cmd_args);
}

void	ft_free_cmd_list(
	t_cmd **cmd_list,
	int cmd_count
)
{
	int	i;

	i = 0;
	while (i < cmd_count)
		ft_free_cmd(&(*cmd_list)[i++]);
	free(*cmd_list);
	*cmd_list = NULL;
}
