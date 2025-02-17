/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:49:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/07 20:31:05 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'pwd' command.
 *
 * @details 	This function prints the current working directory of the
 * 				process to the standard output.
 *
 * @param ctx	The minishell context
 *
 * @return void
 *
 * @author JCHERON
 * @date 2025/01/28 12:49:33
 */

int	ft_pwd(
	t_minishell_ctx *ctx,
	char **args
)
{
	char	*cwd;

	if (args[1])
		return (print_arg_error(ctx, ERR_TOO_MANY_ARGS, args[0]), RET_ERR);
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		print_cmd_errno(ctx, ERR_PWD_CUR_DIR, "pwd", strerror(errno));
		return (RET_ERR);
	}
	ft_putstr_fd(cwd, 1);
	ft_putchar_fd('\n', 1);
	free(cwd);
	return (RET_OK);
}
