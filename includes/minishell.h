/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:16:47 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 11:46:07 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Include our .h

# include "builtins.h"
# include "minishell.h"
# include "libft.h"
# include "env.h"
# include "error.h"
# include "colors.h"
# include "utils.h"

// Include libs

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>
# include <errno.h>

//	ENUMS

//		Should continue

typedef enum e_should_continue
{
	SHOULD_NOT_CONTINUE = 0,
	SHOULD_CONTINUE = 1,
}	t_should_continue;

typedef enum e_should_free
{
	SHOULD_FREE = 1,
	SHOULD_NOT_FREE = 0,
}	t_should_free;

// Minishell context

typedef struct s_minishell_ctx
{
	t_list	*envp;
	char	*p_name;
}	t_minishell_ctx;

//	Functions

//		Bultins

void	ft_pwd(
			t_minishell_ctx *ctx);

//		Error

void	print_gen_error(
			t_minishell_ctx *ctx,
			const char *error);

void	print_arg_error(
			t_minishell_ctx *ctx,
			const char *error,
			const char *cmd_name);

void	print_cmd_errno_error(
			t_minishell_ctx *ctx,
			const char *error,
			const char *cmd_name,
			const char *errno_error);

//		Prompting

char	*build_prompt_message(
			t_minishell_ctx *ctx);

//		Colors

char	*get_term_color(
			t_colors txt_color,
			t_colors back_color);

//		Signals

int		is_any_command_active(
			int is_it);

void	setup_signals(void);

#endif
