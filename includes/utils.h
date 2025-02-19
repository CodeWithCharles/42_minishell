/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:54 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 15:59:05 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Structs

typedef struct s_expand_vars
{
	int		i;
	int		j;
	int		in_simple_quote;
	int		in_double_quote;
}	t_expand_vars;

# define TMP_EMPTY_PATH	"/tmp/minishell_empty"
# define TMP_HERE_DOC_PATH	"/tmp/minishell_here_doc"
# define HERE_DOC_PREFIX	"here_doc> "

// Functions

char	*ft_which(
			const char	*cmd
			);

char	*handle_env_var(
			t_minishell_ctx *ctx,
			char **arg);

char	*expand_variables_in_input(
			t_minishell_ctx *ctx,
			char			*input);

void	init_expand_vars(
			t_expand_vars *vars);

t_cmd	*init_cmd_structs(
			char **cmds);

void	parse_single_cmd(
			t_minishell_ctx *ctx,
			t_cmd *cmd,
			char *cmd_str);

int		parse_redir_input(
			t_minishell_ctx *ctx,
			t_cmd *cmd,
			char ***args);

void	set_redir_in_type(
			t_cmd *cmd,
			char *arg);

void	parse_redir_output(
			t_minishell_ctx *ctx,
			t_cmd *cmd,
			int k,
			char ***args);

t_cmd	*parse_commands(
			t_minishell_ctx *ctx,
			char *input);

int		ft_cmd_count(
			t_cmd **cmd_list);

void	ft_free_cmd(
			t_cmd **cmd);

void	ft_free_cmd_list(
			t_cmd ***cmd,
			int cmd_count);

void	close_pipe(
			int pipe[2]);

bool	is_whitespace(char c);

t_redir	*ft_lastredir(
			t_list *redir_list,
			t_redir_type type);

t_redir	*ft_ltor(
			t_list *redir_list
			);

void	*ft_add_one_to_tab(
			void *ptr,
			size_t size);

t_token	*ft_ltotoken(
			t_list *node
			);

int		validate_env_var_name(
			const char *var_name
			);

#endif
