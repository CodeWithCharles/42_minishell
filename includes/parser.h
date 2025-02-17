/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:13:39 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/17 13:24:51 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_list			*tokenize(
					t_minishell_ctx *ctx,
					const char *input);

void			process_token(
					t_list **tmp,
					t_cmd ***cmds,
					t_parser *parser);

t_cmd			**parse_tokens(
					t_list *tokens);

int				handle_special_tokens(
					t_list **tokens,
					const char *input,
					size_t *i);

int				handle_var_expansion(
					t_list **tokens,
					const char *input,
					size_t *i);

int				handle_word_tokens(
					t_list **tokens,
					const char *input,
					size_t *i,
					int *in_quotes);

void			add_redirection(
					t_list **tmp,
					t_list **redir_list,
					int type);

t_list			*new_redir(
					char *file,
					t_redir_type type);

t_cmd			*new_cmd(void);

t_list			*new_token(
					t_redir_type type,
					char *value);

void			free_token(
					void *token);

void			add_cmd(
					t_cmd ***cmds,
					size_t *cmd_count);

void			handle_parse_error(
					t_minishell_ctx *ctx,
					const char *error,
					t_list **tokens
					);

#endif
