/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:13:39 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 16:56:59 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char			*args_to_string(
					int ac,
					char **args);

t_list			*tokenize(
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

void			handle_unmatched_quotes(
					t_list **tokens);

void			handle_pipe(
					t_cmd ***cmds,
					size_t *cmd_count,
					size_t *args_count);

void			add_redirection(
					t_list **tmp,
					t_list **redir_list,
					int type);

void			add_argument(
					t_cmd **current_cmd,
					t_token *tmp,
					size_t *args_count);

t_list			*new_redir(
					char *file,
					t_redir_type type);

t_cmd			*new_cmd(void);

void			add_token(
					t_list **head,
					t_token *new);

t_list			*new_token(
					t_redir_type type,
					char *value);

void			free_token(
					void *token);

int				handle_redir_in(
					t_list **tokens,
					const char *input,
					size_t *i);

int				handle_redir_out(
					t_list **tokens,
					const char *input,
					size_t *i);

void			add_cmd(
					t_cmd ***cmds,
					size_t *cmd_count);

char	*trim_quotes(
					const char *str);

#endif
