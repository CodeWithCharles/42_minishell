/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:21:38 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/30 17:32:55 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(
	t_minishell_ctx *ctx,
	char **args
)
{
	if (ft_strcmp(args[0], "cd") == 0)
		ft_cd(ctx, args + 1);
	else if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(ctx, args + 1);
	else if (ft_strcmp(args[0], "env") == 0)
		ft_env(ctx);
	else if (ft_strcmp(args[0], "exit") == 0)
		ft_exit(ctx, args + 1);
	// else if (ft_strcmp(args[0], "export") == 0)
	// 	ft_export(ctx, args + 1);
	else if (ft_strcmp(args[0], "pwd") == 0)
		ft_pwd(ctx);
	// else if (ft_strcmp(args[0], "unset") == 0)
	// 	ft_unset(ctx, args + 1);
	return (0);
}
