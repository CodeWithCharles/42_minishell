/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:56:23 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/31 14:08:38 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(
	t_minishell_ctx *ctx,
	char **args
)
{
	// char	*name;
	// char	*value;
	// t_list	*node;

	(void)ctx;
	if (!args || !ft_strchr(*args, '='))
	{
		fd_printf(STDERR_FILENO, "export : invalid format\n");
		return ;
	}
	// skip $ && return NAME=VALUE
}
