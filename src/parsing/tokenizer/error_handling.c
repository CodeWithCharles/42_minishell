/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:00:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 13:41:59 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_parse_error(
	t_minishell_ctx *ctx,
	const char *error,
	t_list **tokens
)
{
	print_gen_error(ctx, error);
	if (tokens)
		ft_lstclear(tokens, free_token);
}
