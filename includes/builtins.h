/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:01:59 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/31 13:54:47 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

void	ft_cd(
			t_minishell_ctx *ctx,
			char **args);

void	ft_echo(
			t_minishell_ctx *ctx,
			char **args);

void	ft_env(
			t_minishell_ctx *ctx);

void	ft_exit(
			t_minishell_ctx *ctx,
			char **args);

void	ft_export(
			t_minishell_ctx *ctx,
			char **args);

void	ft_pwd(
			t_minishell_ctx *ctx);

void	ft_unset(
			t_minishell_ctx *ctx,
			char **args);

#endif
