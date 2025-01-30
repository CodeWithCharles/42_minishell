/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_exit_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:10 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 17:31:08 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

int	ft_last_exit_code(
	int exit_code
)
{
	static int	last_exit_code = 0;

	if (exit_code == -1)
		return (last_exit_code);
	last_exit_code = exit_code;
	return (last_exit_code);
}
