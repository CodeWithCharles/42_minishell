/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gen_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/28 17:05:26 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_gen_error(t_minishell_ctx *ctx, const char *error)
{
	fd_printf(STDERR_FILENO, error,
		get_term_color(COLOR_RED, COLOR_NULL),
		ctx->p_name,
		TERM_RESET);
}
