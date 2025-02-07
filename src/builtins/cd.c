/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:36:02 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/07 20:25:09 by cpoulain         ###   ########.fr       */
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
 *
 * @param ctx	The minishell context
 * @param args	The arguments
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/30 17:19:04
 */
int	ft_cd(
	t_minishell_ctx *ctx,
	char **args
)
{
	char	*path;
	char	*path_tmp;

	if (!args[1])
	{
		path = ft_getenv("HOME");
		if (!path)
			return (print_arg_error(ctx, ERR_CD_HOME_NOT_SET, "cd"), RET_ERR);
	}
	else if (ft_strcmp(args[1], "-") == 0)
		path = ft_getenv("OLDPWD");
	else
		path = args[1];
	path_tmp = ft_to_env_format("OLDPWD", getcwd(NULL, 0));
	ft_setenv(path_tmp);
	free(path_tmp);
	if (chdir(path) == -1)
		return (print_cmd_errno(ctx, ERR_ERRNO, "cd", strerror(errno)), 1);
	else
	{
		path_tmp = ft_realpath(path);
		path_tmp = ft_to_env_format("PWD", path_tmp);
		ft_setenv(path_tmp);
		return (free(path_tmp), RET_OK);
	}
}
