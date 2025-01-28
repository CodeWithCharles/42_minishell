/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt_message.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:24:43 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/28 18:30:41 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*build_prompt_message(t_minishell_ctx *ctx)
{
	char	*message;
	char	*tmp;

	tmp = get_term_color(COLOR_BLACK, COLOR_GRAY);
	message = ft_strdup(tmp);
	free(tmp);
	ft_strcat(&message, ctx->p_name);
	ft_strcat(&message, ":");
	tmp = get_term_color(COLOR_YELLOW, COLOR_CYAN);
	ft_strcat(&message, tmp);
	free(tmp);
	tmp = getcwd(NULL, 0);
	ft_strcat(&message, tmp);
	free(tmp);
	ft_strcat(&message, "/ >"TERM_RESET" ");
	return (message);
}
