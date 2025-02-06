/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:00:34 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/06 09:19:43 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Header implementations

void	ft_free_split(
	char ***split
)
{
	int	i;

	if (!(split) || !(*split))
		return ;
	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		(*split)[i++] = NULL;
	}
	free(*split);
	(*split) = NULL;
}
