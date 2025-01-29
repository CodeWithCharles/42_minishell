/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:25:01 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 12:27:55 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

int	is_valid_builtin(const char *name)
{
	return (ft_strcmp(name, "cd") == 0
		|| ft_strcmp(name, "pwd") == 0
		|| ft_strcmp(name, "exit") == 0
		|| ft_strcmp(name, "env") == 0
		|| ft_strcmp(name, "echo") == 0
		|| ft_strcmp(name, "unset") == 0
		|| ft_strcmp(name, "export") == 0);
}
