/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_errno_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:37:37 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 11:39:42 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_cmd_errno_error(
	t_minishell_ctx *ctx,
	const char *error,
	const char *cmd_name,
	const char *errno_error
)
{
	fd_printf(STDERR_FILENO, error,
		get_term_color(COLOR_RED, COLOR_NULL),
		ctx->p_name,
		cmd_name,
		errno_error,
		TERM_RESET);
}
