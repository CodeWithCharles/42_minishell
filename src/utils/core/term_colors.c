/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:48:11 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/18 09:14:46 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static int	append_color(
				char *color,
				int idx,
				char type,
				char value
				);

// Header implementations

char	*get_term_color(
	t_colors txt_color,
	t_colors back_color
)
{
	char	*color;
	int		idx;

	if (back_color == COLOR_NULL && txt_color == COLOR_NULL)
		return ("");
	color = (char *)malloc(16 * sizeof(char));
	if (!color)
		return (NULL);
	idx = 0;
	color[idx++] = '\033';
	color[idx++] = '[';
	if (back_color != COLOR_NULL && txt_color != COLOR_NULL)
	{
		idx = append_color(color, idx, TERM_COLOR_BACK, (char)back_color);
		color[idx++] = ';';
		idx = append_color(color, idx, TERM_COLOR_FRONT, (char)txt_color);
	}
	else if (txt_color != COLOR_NULL)
		idx = append_color(color, idx, TERM_COLOR_FRONT, (char)txt_color);
	else if (back_color != COLOR_NULL)
		idx = append_color(color, idx, TERM_COLOR_BACK, (char)back_color);
	color[idx++] = 'm';
	color[idx] = '\0';
	return (color);
}

// Static implementations

static int	append_color(
	char *color,
	int idx,
	char place,
	char value
)
{
	color[idx++] = place;
	color[idx++] = value;
	return (idx);
}
