/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:17:04 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 12:49:21 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	find_first_quote(
	char *str
)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	return (i);
}

static size_t	find_last_quote(
	char *str,
	char quote_char,
	size_t start
)
{
	size_t	end;

	end = ft_strlen(str) - 1;
	while (end > start && str[end] != quote_char)
		end--;
	return (end);
}

static void	remove_quotes(
	char **str,
	size_t start,
	size_t end
)
{
	char	*new_str;

	new_str = malloc(ft_strlen(*str));
	if (!new_str)
		return ;
	ft_strlcpy(new_str, *str, start + 1);
	ft_strlcat(new_str, *str + start + 1, end);
	ft_strlcat(new_str, *str + end + 1, ft_strlen(*str));
	free(*str);
	*str = new_str;
}

void	trim_quotes(
	char **str
)
{
	size_t	start;
	size_t	end;
	char	quote_char;

	if (!str || !*str || ft_strlen(*str) < 2)
		return ;
	start = find_first_quote(*str);
	if ((*str)[start] != '\'' && (*str)[start] != '\"')
		return ;
	quote_char = (*str)[start];
	end = find_last_quote(*str, quote_char, start);
	if (end > start)
	{
		if (quote_char == '\"')
			expand_variable(str);
		remove_quotes(str, start, end);
	}
}
