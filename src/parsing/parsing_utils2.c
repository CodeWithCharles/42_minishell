/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:46:53 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/01 14:51:23 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initialize the expand_vars structure
 *
 * @details This function will initialize the expand_vars structure
 *
 * @param vars The expand_vars structure
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/02/01 11:47:58
 */
void	init_expand_vars(
	t_expand_vars *vars
)
{
	vars->i = 0;
	vars->j = 0;
	vars->in_simple_quote = 0;
	vars->in_double_quote = 0;
}
