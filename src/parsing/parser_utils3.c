/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:26:04 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 16:58:17 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_list	*new_token(t_redir_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = ft_strdup(value);
	return (ft_lstnew(token));
}

void	free_token(void *token)
{
	t_token	*t;

	t = (t_token *)token;
	if (t)
	{
		if (t->value)
			free(t->value);
		free(t);
	}
}
