/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:54 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 19:35:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define TMP_EMPTY_PATH	"/tmp/minishell_empty"
# define TMP_HERE_DOC_PATH	"/tmp/minishell_here_doc"
# define HERE_DOC_PREFIX	"here_doc> "

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

#endif
