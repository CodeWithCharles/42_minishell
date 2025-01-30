/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:16:47 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 17:04:28 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Include our .h

# include "libft.h"
# include "context.h"
# include "builtins.h"
# include "env.h"
# include "error.h"
# include "colors.h"
# include "utils.h"
# include "cmd.h"

// Include libs

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdbool.h>

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

//	Functions

//		Bultins

void	ft_pwd(
			t_minishell_ctx *ctx);

//		Pathing

int		is_valid_builtin(
			const char *name);

void	get_cmd(
			t_minishell_ctx *ctx,
			t_cmd *cmd);

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
