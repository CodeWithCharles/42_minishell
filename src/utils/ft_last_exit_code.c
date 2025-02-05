/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_exit_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:10 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 12:09:07 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

int	ft_last_exit_code(
	int exit_code
)
{
	char		*exit_code_as_str;
	char		*tmp;
	static int	last_exit_code = 0;

	if (exit_code == -1)
		return (last_exit_code);
	last_exit_code = exit_code;
	exit_code_as_str = ft_itoa(exit_code);
	if (!exit_code_as_str)
		return (last_exit_code);
	tmp = ft_strjoin("?", exit_code_as_str);
	free(exit_code_as_str);
	if (tmp)
	{
		ft_setenv(tmp);
		free(tmp);
	}
	return (last_exit_code);
}
