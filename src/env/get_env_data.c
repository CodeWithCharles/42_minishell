/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:34:59 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 12:37:46 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_var_name(
	t_list	*node
)
{
	return (((t_env_var *)node->content)->var_name);
}

char	*get_env_var_value(
	t_list	*node
)
{
	return (((t_env_var *)node->content)->value);
}
