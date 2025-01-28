/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:49:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 12:55:01 by jcheron          ###   ########.fr       */
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

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_putstr_fd("pwd: error retrieving current directory: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	ft_putstr_fd(cwd, 1);
}
