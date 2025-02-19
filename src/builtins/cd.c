/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:36:02 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 15:43:16 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static prototypes

static void	_set_new_pwd(
				char **new_path);

static void	_set_old_pwd(void);

// Header implementations

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

	if (!args[1] || (args[1] && ft_strcmp(args[1], "~") == 0))
	{
		path = ft_getenv("HOME");
		if (!path)
			return (print_arg_error(ctx, ERR_CD_HOME_NOT_SET, "cd"), RET_ERR);
	}
	else if (ft_strcmp(args[1], "-") == 0)
		path = ft_getenv("OLDPWD");
	else
		path = ft_strdup(args[1]);
	_set_old_pwd();
	if (chdir(path) == -1)
	{
		free(path);
		print_cmd_errno(ctx, ERR_ERRNO, "cd", strerror(errno));
		return (RET_ERR);
	}
	else
		return (_set_new_pwd(&path), RET_OK);
}

// Static implementations

static void	_set_new_pwd(
	char **new_path
)
{
	char	*real_path;
	char	*env_var;

	real_path = ft_realpath(*new_path);
	env_var = ft_to_env_format("PWD", real_path);
	free(real_path);
	ft_setenv(env_var);
	free(env_var);
	free(*new_path);
	*new_path = NULL;
}

static void	_set_old_pwd(void)
{
	char	*path_tmp;
	char	*env_var;

	path_tmp = getcwd(NULL, 0);
	env_var = ft_to_env_format("OLDPWD", path_tmp);
	free(path_tmp);
	ft_setenv(env_var);
	free(env_var);
}
