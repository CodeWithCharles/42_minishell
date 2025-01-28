/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:16:47 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/28 17:04:31 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "minishell.h"
# include "libft.h"
# include "env.h"
# include "error.h"
# include "colors.h"
# include <readline/readline.h>
# include <readline/history.h>

//	ENUMS

//		Should continue

typedef enum e_should_continue
{
	SHOULD_NOT_CONTINUE = 0,
	SHOULD_CONTINUE = 1,
}	t_should_continue;

// Minishell context

typedef struct s_minishell_ctx
{
	t_list	*envp;
	char	*p_name;
}	t_minishell_ctx;

//	Functions

//		Error

void	print_gen_error(
			t_minishell_ctx *ctx,
			const char *error);

//		Prompting

char	*build_prompt_message(t_minishell_ctx *ctx);

//		Colors

char	*get_term_color(
			t_colors txt_color,
			t_colors back_color);

#endif
