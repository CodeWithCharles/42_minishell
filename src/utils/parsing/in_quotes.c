/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:31:11 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 14:31:25 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Header implementations

int	_in_quotes(
	const char *token
)
{
	return ((token[0] == '\'' && token[ft_strlen(token) - 1] == '\'')
		|| (token[0] == '\"' && token[ft_strlen(token) - 1] == '\"'));
}
