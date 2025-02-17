/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:13:39 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/17 16:08:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//	Functions

//		Tokenizer

t_list	*tokenize(
			t_minishell_ctx *ctx,
			const char *input);

int		handle_special_tokens(
			t_list **tokens,
			const char *input,
			size_t *i);

int		handle_var_expansion(
			t_list **tokens,
			const char *input,
			size_t *i);

int		handle_word_tokens(
			t_list **tokens,
			const char *input,
			size_t *i,
			int *in_quotes);

t_list	*new_token(
			t_redir_type type,
			char *value);

void	free_token(
			void *token);

void	handle_parse_error(
			t_minishell_ctx *ctx,
			const char *error,
			t_list **tokens);

int		check_invalid_pipe(
			const char *input);

//		Commander

t_cmd	**parse_tokens(
			t_list *tokens);

void	add_redirection(
			t_list **tmp,
			t_list **redir_list,
			int type);

t_list	*new_redir(
			char *file,
			t_redir_type type);

t_cmd	*new_cmd(void);

void	add_cmd(
			t_cmd ***cmds,
			size_t *cmd_count);

void	expand_variable(
			char **input);

int		_in_single_quotes(
			const char *token);

#endif
