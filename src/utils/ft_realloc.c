/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:04:43 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 09:04:26 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (ft_calloc(size, 1));
	new = ft_calloc(size, 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
