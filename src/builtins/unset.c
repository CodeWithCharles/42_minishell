/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:16:19 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/17 15:39:52 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(
	t_minishell_ctx *ctx,
	char **args
)
{
	int		i;

	(void)ctx;
	i = 1;
	while (args[i])
		ft_unsetenv(args[i++]);
	return (RET_OK);
}
