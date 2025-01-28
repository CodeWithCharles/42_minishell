/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:36:02 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 12:47:09 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../third_party/42_libft_full/libft.h"
#include <errno.h>
#include <string.h>

/**
 * @brief		Mimics the behavior of the Unix 'cd' command.
 *
 * @details 	This function changes the current working directory of the
 * 				process to the directory provided as the first argument. If
 * 				no argument is provided, the current working directory is
 * 				changed to the home directory of the user.
 */
void	ft_cd(
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
			ft_putstr_fd("cd: HOME not set\n", 2);
			return ;
		}
		path = home;
	}
	else
		path = args[0];
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
	}
}
