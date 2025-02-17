/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:51:54 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/17 15:50:20 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	extract_var_name(char *var_name, char **tmp)
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

void	expand_variable(char **input)
{
	char	*tmp;
	char	*result;
	char	*var_name;
	char	*var_value;
	char	saved_char;

	tmp = ft_strchr(*input, '$');
	if (!tmp)
		return ;

	result = ft_strndup(*input, tmp - *input);
	var_name = tmp + 1;
	saved_char = extract_var_name(var_name, &tmp);
	var_value = ft_getenv(var_name);
	tmp[0] = saved_char;
	if (var_value)
	{
		ft_strcat(&result, var_value);
		free(var_value);
	}
	ft_strcat(&result, tmp);
	free(*input);
	*input = result;
}

int	_in_single_quotes(const char *token)
{
	return (token[0] == '\'' && token[ft_strlen(token) - 1] == '\'');
}
