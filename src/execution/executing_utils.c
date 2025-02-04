/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:06:06 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/04 13:25:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_post_builtin(
	t_executing_ctx *exec_ctx,
	char **envp
)
{
	_clean_exec_ctx(exec_ctx);
	if (envp)
		ft_free_split(envp);
	if (ft_envp(NULL))
		ft_lstclear(ft_envp(NULL), free);
}
