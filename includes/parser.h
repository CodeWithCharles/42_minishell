/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:13:39 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/13 14:13:17 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char			*args_to_string(
					int ac,
					char **args);

t_token			*tokenize(
					const char *input);

void			process_token(
					t_token **tmp,
					t_cmd ***cmds,
					t_parser *parser);

t_cmd			**parse_tokens(
					t_token *tokens);

int				handle_special_tokens(
					t_token **tokens,
					const char *input,
					size_t *i);

int				handle_var_expansion(
					t_token **tokens,
					const char *input,
					size_t *i);

int				handle_word_tokens(
					t_token **tokens,
					const char *input,
					size_t *i,
					int *in_quotes);

t_token			*handle_unmatched_quotes(
					t_token *tokens);

void			handle_pipe(
					t_cmd ***cmds,
					size_t *cmd_count,
					size_t *args_count);

void			add_redirection(
					t_token **tmp,
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
					t_token **head,
					t_token *new);

t_token			*new_token(
					t_redir_type type,
					char *value);

void			free_tokens(
					t_token *tokens);

int				handle_redir_in(
					t_token **tokens,
					const char *input,
					size_t *i);

int				handle_redir_out(
					t_token **tokens,
					const char *input,
					size_t *i);

void			add_cmd(
					t_cmd ***cmds,
					size_t *cmd_count);

char	*trim_quotes(
					const char *str);

#endif
