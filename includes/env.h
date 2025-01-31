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

// Functions

t_list	**ft_envp(
			char **envp);

char	*get_env_value(
			t_minishell_ctx *ctx,
			char *name);

char	*get_env_name(
			char *arg);

char	*ft_getenv(
			char *name);

void	ft_setenv(
			char *variable);

void	ft_unsetenv(
			char *name);

int		ft_env_varcmp(
			char *s1,
			char *s2);

#endif
