/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:04:43 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 13:47:44 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;
	size_t	old_size;

	if (!ptr)
		return (malloc(size));
	old_size = sizeof(ptr);
	if (size <= old_size)
		return (ptr);
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
