/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:24:22 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 16:54:52 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include "minishell.h"

typedef struct s_env_var
{
	char	*var_name;
	char	*value;
}	t_env_var;

// Functions

t_list	*init_env(
			char **envp);

char	*get_env_value(
			t_minishell_ctx *ctx,
			char *name);

char	*get_env_name(
			char *arg);

#endif
