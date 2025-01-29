/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:49:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/29 11:47:11 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../third_party/42_libft_full/libft.h"
#include <errno.h>
#include <string.h>

/**
 * @brief		Mimics the behavior of the Unix 'pwd' command.
 *
 * @details 	This function prints the current working directory of the
 * 				process to the standard output.
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
