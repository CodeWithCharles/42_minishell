/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:46 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 11:24:47 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_commands(
	t_minishell_ctx *ctx,
	char *input
)
{
	char	**cmds;
	t_cmd	*cmd_structs;
	int		i;

	(void)ctx;
	cmds = spooq(input, '|');
	if (!cmds)
		return (NULL);
	cmd_structs = init_cmd_structs(cmds);
	if (!cmd_structs)
		return (NULL);
	i = 0;
	while (cmds[i])
	{
		parse_single_cmd(ctx, &cmd_structs[i], cmds[i]);
		i++;
	}
	cmd_structs[i].cmd_name = NULL;
	return (ft_free_split(cmds), cmd_structs);
}
