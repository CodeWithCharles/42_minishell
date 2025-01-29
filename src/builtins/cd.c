/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:36:02 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/29 12:34:07 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'cd' command.
 *
 * @details 	This function changes the current working directory of the
 * 				process to the directory provided as the first argument. If
 * 				no argument is provided, the current working directory is
 * 				changed to the home directory of the user.
 */
void	ft_cd(
	t_minishell_ctx *ctx,
	char **args
)
{
	char	*home;
	char	*path;

	if (!args[0])
	{
		home = getenv("HOME");
		if (!home)
		{
			print_arg_error(ctx, ERR_CD_HOME_NOT_SET, "cd");
			return ;
		}
		path = home;
	}
	else
		path = args[0];
	if (chdir(path) == -1)
	{
		fd_printf(
			2,
			"cd: %s : %s\n",
			strerror(errno),
			path);
	}
}
