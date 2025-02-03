/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:46 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/03 17:03:32 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Parse commands
 *
 * @details This function will parse commands and fill the command
 * 			structure with the command name, arguments and redirections.
 *
 * @param ctx The minishell context
 * @param cmd The command structure
 *
 * @return t_cmd* The command structure containing the parsed commands
 *
 * @author jcheron
 * @date 2025/01/31 14:21:46
 */
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
