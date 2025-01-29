/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:10 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/28 18:21:15 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define TERM_RESET					"\033[0m"

# define TERM_UP					"\033[1A"
# define TERM_CLEAR_LINE			"\033[2K\r"

# define TERM_COLOR_FRONT			'3'
# define TERM_COLOR_BACK			'4'

typedef enum e_colors
{
	COLOR_BLACK = '0',
	COLOR_RED = '1',
	COLOR_GREEN = '2',
	COLOR_YELLOW = '3',
	COLOR_BLUE = '4',
	COLOR_MAGENTA = '5',
	COLOR_CYAN = '6',
	COLOR_GRAY = '7',
	COLOR_NULL = '~',
}	t_colors;

#endif
