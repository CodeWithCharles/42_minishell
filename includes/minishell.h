/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:16:47 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/05 11:08:45 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Include our .h

# include "libft.h"
# include "cmd.h"
# include "context.h"
# include "builtins.h"
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
# include <sys/stat.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>

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

//	Functions

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

//		Executing

int		is_builtin_pipeable(
			const char *name);

int		handle_redirection(
			t_minishell_ctx *ctx,
			t_cmd *cmd);

void	close_pipes(
			int cmd_count,
			int pipes[][2]);

void	close_fds_if_open(
			t_cmd *cmd);

int		setup_pipes(
			t_minishell_ctx *ctx,
			int cmd_count,
			int (*pipes)[2]);

int		fork_command(
			t_minishell_ctx *ctx,
			t_cmd *cmd,
			t_executing_ctx *exec_ctx,
			int p_fd[2]);

int		setup_redirections(
			t_minishell_ctx *ctx,
			t_executing_ctx *exec_ctx,
			t_cmd *cmd,
			int p_fd[2]);

void	handle_here_doc(
			t_minishell_ctx *ctx,
			t_cmd *cmd);

void	execute_pipeline(
			t_minishell_ctx *ctx,
			t_cmd *cmd_list);

void	clean_exec_ctx(
			t_executing_ctx *exec_ctx);

void	execute_builtin(
			t_minishell_ctx *ctx,
			t_executing_ctx *exec_ctx,
			t_cmd *cmd,
			char **envp);

void	ft_free_post_builtin(
			t_executing_ctx *exec_ctx,
			char **envp);

int		setup_outfile_fd(
			t_minishell_ctx *ctx,
			t_cmd *cmd);

int		setup_infile_fd(
			t_minishell_ctx *ctx,
			t_cmd *cmd);

int		setup_cmd_fd_io(
			t_minishell_ctx *ctx,
			t_cmd *cmd);

#endif
