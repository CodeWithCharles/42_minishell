/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_errno.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:37:37 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/07 20:25:28 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_cmd_errno(
	t_minishell_ctx *ctx,
	const char *error,
	const char *cmd_name,
	const char *errno_error
)
{
	char	*color;

	color = get_term_color(COLOR_RED, COLOR_NULL);
	fd_printf(STDERR_FILENO, error,
		color,
		ctx->p_name,
		cmd_name,
		errno_error,
		TERM_RESET);
	free(color);
}
