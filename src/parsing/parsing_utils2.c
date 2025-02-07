/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:46:53 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/06 09:43:37 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initialize the expand_vars structure
 *
 * @details This function will initialize the expand_vars structure
 *
 * @param vars The expand_vars structure
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
void	init_expand_vars(
	t_expand_vars *vars
)
{
	vars->i = 0;
	vars->j = 0;
	vars->in_simple_quote = 0;
	vars->in_double_quote = 0;
}

void	set_redir_in_type(
	t_cmd *cmd,
	char *arg
)
{
	if (ft_strcmp(arg, "<") == 0)
		cmd->redir_in.type = REDIR_INPUT;
	else
		cmd->redir_in.type = REDIR_HEREDOC;
}
