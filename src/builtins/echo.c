/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:03:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/29 11:44:34 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief		Mimics the behavior of the Unix 'echo' command.
 *
 * @details 	This function prints the provided arguments to the standard
 * 				outuput. If the first argument is "-n", it suppresses the
 * 				new line at the end of the output. Each argument is seperated
 * 				by a single space when printed.
 */
void	ft_echo(
	t_minishell_ctx *ctx,
	char **args
)
{
	int		i;
	int		n_flag;

	(void)ctx;
	i = 0;
	n_flag = 0;
	if (args[0] && !ft_strcmp(args[0], "-n"))
	{
		n_flag = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
}
