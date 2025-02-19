/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:44:50 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 11:11:03 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_free_redirs(
	void *redir
)
{
	if (((t_redir *)redir)->file)
		free(((t_redir *)redir)->file);
	free((t_redir *)redir);
}

void	ft_free_cmd(
	t_cmd **cmd
)
{
	if (!*cmd)
		return ;
	if ((*cmd)->cmd_name)
		free((*cmd)->cmd_name);
	if ((*cmd)->cmd_args)
		ft_free_split(&(*cmd)->cmd_args);
	if ((*cmd)->redir_list)
		ft_lstclear(&((*cmd)->redir_list), ft_free_redirs);
	free((*cmd));
	*cmd = NULL;
}

void	ft_free_cmd_list(
	t_cmd ***cmd_list,
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
