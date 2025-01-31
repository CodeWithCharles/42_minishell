/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:01:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/31 11:09:08 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);

	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		if (ft_memcmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

char	*ft_strreplace(
	char *str,
	char *old,
	char *new
)
{
	char	*result;
	char	*insert;
	char	*tmp;
	size_t	len_front;
	size_t	len_old;
	size_t	len_new;

	len_front = 0;
	len_old = ft_strlen(old);
	len_new = ft_strlen(new);
	result = ft_strdup(str);
	insert = result;
	while ((tmp = ft_strstr(insert, old)))
	{
		insert = tmp + len_old;
		len_front = tmp - result;
		result = ft_realloc(result, ft_strlen(result) + len_new - len_old + 1);
		insert = result + len_front;
		ft_memmove(insert + len_new, insert + len_old, ft_strlen(insert) - len_front);
		ft_memcpy(insert, new, len_new);
	}
	return (result);
}
