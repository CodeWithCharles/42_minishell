/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:13:39 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/11 16:35:09 by jcheron          ###   ########.fr       */
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
					t_cmd **current_cmd,
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

t_cmd			*handle_pipe(
					t_cmd **cmds,
					t_cmd *current_cmd,
					size_t *cmd_count,
					size_t *args_count);

void			add_redirection(
					t_token **tmp,
					t_redir_node **redir_list,
					int type);

void			add_argument(
					t_cmd *current_cmd,
					t_token *tmp,
					size_t *args_count);

t_redir_node	*new_redir(
					char *file,
					t_redir_type type);

void			add_redir_node(
					t_redir_node **head,
					t_redir_node *new);

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

t_cmd			**add_cmd(
					t_cmd **cmds,
					t_cmd *current_cmd,
					size_t *cmd_count);

char			*ft_strndup(
					const char *s,
					size_t n);

#endif
