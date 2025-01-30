/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_out_of_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:31 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/30 17:01:51 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

static bool	_ft_is_quote(char c, bool *in_single, bool *in_double)
{
	if (c == '\'' && !(*in_double))
	{
		*in_single = !(*in_single);
		return (true);
	}
	if (c == '\"' && !(*in_single))
	{
		*in_double = !(*in_double);
		return (true);
	}
	return (false);
}

static char	*_ft_strtok_quotes(char *str, char sep)
{
	static char	*next = NULL;
	char		*start;
	bool		in_single;
	bool		in_double;

	if (str)
		next = str;
	if (!next || *next == '\0')
		return (NULL);
	in_single = false;
	in_double = false;
	while (*next == sep)
		next++;
	start = next;
	while (*next && (*next != sep || in_single || in_double))
	{
		_ft_is_quote(*next, &in_single, &in_double);
		next++;
	}
	if (*next == sep)
		*(next++) = '\0';
	return (start);
}

static size_t	_count_words(
	char *str,
	char sep
)
{
	size_t	count;
	bool	in_single_quotes;
	bool	in_double_quotes;

	count = 0;
	in_single_quotes = false;
	in_double_quotes = false;
	while (*str)
	{
		if (_ft_is_quote(*str, &in_single_quotes, &in_double_quotes))
			++str;
		else if (!in_single_quotes && *str == sep)
		{
			++count;
			++str;
		}
		else
			++str;
	}
	return (count + 1);
}

char	**spooq(char *str, char sep)
{
	char	**split;
	size_t	words;
	size_t	i;
	char	*token;

	words = _count_words(str, sep);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	token = _ft_strtok_quotes(str, sep);
	while (token)
	{
		split[i] = ft_strdup(token);
		if (!split[i])
		{
			ft_free_split(split);
			return (NULL);
		}
		token = _ft_strtok_quotes(NULL, sep);
		++i;
	}
	split[i] = NULL;
	return (split);
}
