/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:55:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 12:59:34 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_path(
	t_minishell_ctx *ctx
)
{
	t_list	*current;

	current = ctx->envp;
	while (current)
	{
		if (ft_strncmp(get_env_var_name(current), "PATH", 4) == 0)
			return (get_env_var_value(current));
		current = current->next;
	}
	return (NULL);
}
