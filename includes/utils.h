/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:54 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/01 11:46:23 by onkeltag         ###   ########.fr       */
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

// Functions

void	ft_free_split(
			char **split);

char	**spooq(
			char *str,
			char sep);

char	*ft_strtok_quotes(char *str, char sep);

int		ft_last_exit_code(
			int exit_code);

void	ft_lstremove(
			t_list **lst,
			void (*del)()
			);

char	*ft_which(
			const char	*cmd
			);

char	*handle_env_var(
			t_minishell_ctx *ctx,
			char **arg);

char	*expand_variables_in_input(
			t_minishell_ctx *ctx,
			char			*input);

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

void	parse_redir_input(
			t_minishell_ctx *ctx,
			t_cmd *cmd,
			char ***args);

void	parse_redir_output(
			t_minishell_ctx *ctx,
			t_cmd *cmd,
			int k,
			char ***args);

t_cmd	*parse_commands(
			t_minishell_ctx *ctx,
			char *input);

#endif
