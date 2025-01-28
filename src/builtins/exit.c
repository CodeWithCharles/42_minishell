/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:16 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 13:22:10 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../third_party/42_libft_full/libft.h"

/**
 * @brief		Mimics the behavior of the Unix 'exit' command.
 *
 * @details 	This function exits the shell with the status provided as the
 * 				first argument. If no argument is provided, the shell exits
 * 				with the status 0.
 */

void	ft_exit(
			char **args
			)
{
	int		status;

	status = 0;
	if (args[0])
	{
		if (!ft_isdigit(args[0][0]))
		{
			fd_printf(2, "exit: %s: numeric argument required\n", args[0]);
			exit(255);
		}
		status = ft_atoi(args[0]);
	}
	exit(status);
}
