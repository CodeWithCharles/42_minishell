/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:51:54 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/17 18:29:51 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static prototypes

static void	append_var_value(
				char **result,
				char *var_name);

static char	*extract_var_and_expand(
				char *input,
				char **result);

static char	extract_var_name(
				char *var_name,
				char **tmp);

// Header implementations

void	expand_variable(char **input)
{
	char	*tmp;
	char	*result;
	size_t	new_size;
	char	*start;

	new_size = ft_strlen(*input) + 1;
	result = malloc(new_size);
	if (!result)
		return ;
	result[0] = '\0';
	start = *input;
	tmp = *input;
	while (tmp && *tmp)
	{
		if (*tmp == '$')
			tmp = extract_var_and_expand(tmp, &result);
		else
			tmp++;
	}
	ft_strlcat(result, start, new_size);
	free(*input);
	*input = result;
}

int	_in_single_quotes(const char *token)
{
	return (token[0] == '\'' && token[ft_strlen(token) - 1] == '\'');
}

// Static implementations

static void	append_var_value(
	char **result,
	char *var_name
)
{
	char	*var_value;
	size_t	new_size;
	char	*new_result;

	var_value = ft_getenv(var_name);
	if (!var_value)
		return ;
	new_size = ft_strlen(*result) + ft_strlen(var_value) + 1;
	new_result = malloc(new_size);
	if (!new_result)
		return ;
	new_result[0] = '\0';
	ft_strlcat(new_result, *result, new_size);
	ft_strlcat(new_result, var_value, new_size);
	free(var_value);
	free(*result);
	*result = new_result;
}

static char	extract_var_name(
	char *var_name,
	char **tmp
)
{
	int		i;
	char	saved_char;

	i = 0;
	while (ft_isalpha(var_name[i]) || var_name[i] == '?')
		i++;
	saved_char = var_name[i];
	*tmp = var_name + i;
	var_name[i] = '\0';
	return (saved_char);
}

static char	*extract_var_and_expand(
	char *input,
	char **result
)
{
	char	*var_name;
	char	*tmp;
	char	saved_char;

	var_name = input + 1;
	tmp = input + 1;
	saved_char = extract_var_name(var_name, &tmp);
	append_var_value(result, var_name);
	tmp[0] = saved_char;
	return (tmp);
}
