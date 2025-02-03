/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:31:40 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/03 20:08:26 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_arg_error(
	t_minishell_ctx *ctx,
	const char *error,
	const char *cmd_name
)
{
	char	*color;

	color = get_term_color(COLOR_RED, COLOR_NULL);
	fd_printf(STDERR_FILENO, error,
		color,
		ctx->p_name,
		cmd_name,
		TERM_RESET);
	free(color);
}
