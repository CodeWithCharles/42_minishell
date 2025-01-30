/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:30:21 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 12:46:44 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_list_to_tab(
	t_minishell_ctx *ctx,
	char ***envp_tab
)
{
	t_list	*envp_list;
	size_t	list_size;
	char	*tmp;
	size_t	i;

	i = 0;
	envp_list = ctx->envp;
	list_size = ft_lstsize(envp_list);
	*envp_tab = malloc((size + 1) * sizeof(void *));
	while (envp_list)
	{
		tmp = malloc(ft_strlen(get_env_var_name(envp_list))
				+ ft_strlen(get_env_var_value(envp_list)) + 1);
		ft_strcat(&tmp, get_env_var_name(var_name));
		tmp[ft_strlen(get_env_var_name(var_name))] = '=';
		ft_strcat(&tmp, get_env_var_value(var_value));
		(*envp_tab)[i++] = ft_strdup(tmp);
		envp_list = envp_list->next;
		free(tmp);
		tmp = NULL;
	}
	(*envp_tab)[i] = NULL;
}
