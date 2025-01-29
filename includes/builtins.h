/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:01:59 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/29 12:35:24 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

void	ft_cd(
	t_minishell_ctx *ctx,
	char **args
);

void	ft_echo(
	t_minishell_ctx *ctx,
	char **args
);

void	ft_env(
	t_minishell_ctx *ctx
);

void	ft_exit(
	t_minishell_ctx *ctx,
	char **args
);

void	ft_export(
	t_minishell_ctx *ctx,
	char **args
);

void	ft_pwd(
	t_minishell_ctx *ctx
);

void	ft_unset(
	t_minishell_ctx *ctx,
	char **args
);

int		execute_builtin(
	t_minishell_ctx *ctx,
	char **args
);

#endif