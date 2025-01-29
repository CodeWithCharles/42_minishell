/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:24:22 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 15:37:29 by onkeltag         ###   ########.fr       */
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

#endif
