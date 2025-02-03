/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:10:45 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/03 17:13:17 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_count(
	t_cmd *cmd_list
)
{
	int	i;

	i = 0;
	while (cmd_list[i].cmd_name)
		i++;
	return (i);
}
