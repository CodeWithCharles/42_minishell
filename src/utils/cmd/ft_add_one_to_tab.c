/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_one_to_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:04:43 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/17 13:20:38 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_add_one_to_tab(void *ptr, size_t size)
{
	char	*new_ptr;

	if (!ptr)
		return (malloc(size));
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_bzero(new_ptr, size);
	ft_memcpy(new_ptr, ptr, size - sizeof(char *));
	free(ptr);
	return (new_ptr);
}
