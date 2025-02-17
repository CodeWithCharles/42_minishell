/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:01:59 by onkeltag          #+#    #+#             */
/*   Updated: 2025/02/07 20:27:21 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		ft_cd(
			t_minishell_ctx *ctx,
			char **args);

int		ft_echo(
			t_minishell_ctx *ctx,
			char **args);

int		ft_env(
			t_minishell_ctx *ctx,
			char **args);

void	ft_exit(
			t_minishell_ctx *ctx,
			t_executing_ctx *exec_ctx,
			char **args);

int		ft_export(
			t_minishell_ctx *ctx,
			char **args);

int		ft_pwd(
			t_minishell_ctx *ctx,
			char **args);

int		ft_unset(
			t_minishell_ctx *ctx,
			char **args);

#endif
