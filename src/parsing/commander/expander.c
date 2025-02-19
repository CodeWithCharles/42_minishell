/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:51:54 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/19 14:38:01 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Static prototypes

static char	*extract_var_and_expand(
				char **input,
				char **result);

static char	extract_var_name(
				char *var_name,
				char **tmp);

static void	append_var_value(
				char **result,
				char *var_name);

static void	append_str(
				char **result,
				char *str,
				size_t len);

// Header implementations
void	expand_variable(char **input)
{
	char	*tmp;
	char	*result;
	char	*start;

	if (!input || !*input)
		return ;
	result = ft_strdup("");
	if (!result)
		return ;
	tmp = *input;
	while (*tmp)
	{
		if (*tmp == '$')
			tmp = extract_var_and_expand(&tmp, &result);
		else
		{
			start = tmp;
			while (*tmp && *tmp != '$')
				tmp++;
			append_str(&result, start, tmp - start);
		}
	}
	free(*input);
	*input = result;
}

// Static implementations

static void	append_str(char **result, char *str, size_t len)
{
	size_t	new_size;
	char	*new_result;

	if (!str || len == 0)
		return ;
	new_size = ft_strlen(*result) + len + 1;
	new_result = malloc(new_size);
	if (!new_result)
		return ;
	ft_strlcpy(new_result, *result, new_size);
	ft_strlcat(new_result, str, new_size);
	free(*result);
	*result = new_result;
}

static void	append_var_value(char **result, char *var_name)
{
	char	*var_value;

	var_value = ft_getenv(var_name);
	if (var_value)
	{
		append_str(result, var_value, ft_strlen(var_value));
		free(var_value);
	}
}

static char	extract_var_name(char *var_name, char **tmp)
{
	int		i;
	char	saved_char;

	i = 0;
	while (ft_isalnum(var_name[i]) || var_name[i] == '?')
		i++;
	saved_char = var_name[i];
	*tmp = var_name + i;
	var_name[i] = '\0';
	return (saved_char);
}

static char	*extract_var_and_expand(char **input, char **result)
{
	char	*var_name;
	char	*tmp;
	char	saved_char;

	tmp = *input + 1;
	var_name = tmp;
	saved_char = extract_var_name(var_name, &tmp);
	append_var_value(result, var_name);
	*tmp = saved_char;
	return (tmp);
}
