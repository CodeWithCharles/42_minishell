/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:24:22 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 15:51:53 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

// Functions

t_list	**ft_envp(
			char **envp);

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
