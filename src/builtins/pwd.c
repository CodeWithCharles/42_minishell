/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:49:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 14:58:53 by onkeltag         ###   ########.fr       */
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

void	ft_pwd(
	t_minishell_ctx *ctx
)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		print_cmd_errno_error(ctx, ERR_PWD_CUR_DIR, "pwd", strerror(errno));
		return ;
	}
	ft_putstr_fd(cwd, 1);
	ft_putchar_fd('\n', 1);
}
