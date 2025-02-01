/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:46:53 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/01 11:48:18 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_expand_vars(
	t_expand_vars *vars
)
{
	vars->i = 0;
	vars->j = 0;
	vars->in_simple_quote = 0;
	vars->in_double_quote = 0;
}
