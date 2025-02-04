/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:16:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/04 16:16:29 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	_custom_exit(
	char **envp,
	int exit_code
)
{
	if (envp)
		ft_free_split(envp);
	exit(exit_code);
}

static void	execute_external(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	char **envp
)
{
	get_cmd(ctx, cmd);
	if (cmd->exit_code == CODE_CMD_NOT_FOUND)
		_custom_exit(envp, CODE_CMD_NOT_FOUND);
	if (execve(cmd->cmd_name, cmd->cmd_args, envp) == -1)
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		_custom_exit(envp, CODE_CMD_NOT_EXECUTABLE);
	}
}

void	execute_builtin(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd *cmd,
	char **envp
)
{
	if (ft_strcmp(cmd->cmd_name, "cd") == 0)
		ft_cd(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "pwd") == 0)
		ft_pwd(ctx);
	else if (ft_strcmp(cmd->cmd_name, "env") == 0)
		ft_env(ctx);
	else if (ft_strcmp(cmd->cmd_name, "export") == 0)
		ft_export(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "exit") == 0)
		ft_exit(ctx, exec_ctx, cmd, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "echo") == 0)
		ft_echo(ctx, cmd->cmd_args);
	else
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		exit(CODE_CMD_NOT_EXECUTABLE);
	}
	ft_free_post_builtin(exec_ctx, envp);
	ft_free_cmd(cmd);
	free(cmd);
	exit(0);
}

int	fork_command(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	t_executing_ctx *exec_ctx
)
{
	int		cmd_pid;
	char	**envp;

	if (ft_envp_tab(&envp) == RET_ERR)
		return (RET_ERR);
	cmd_pid = fork();
	if (cmd_pid == -1)
		return (ft_free_split(envp), RET_ERR);
	if (cmd_pid == 0)
	{
		setup_redirections(cmd, exec_ctx);
		close_pipes(exec_ctx->cmd_count, exec_ctx->pipes);
		if (is_valid_builtin(cmd->cmd_name))
			execute_builtin(ctx, exec_ctx, cmd, envp);
		else
			execute_external(ctx, cmd, envp);
	}
	else
		exec_ctx->pids[exec_ctx->curr_idx] = cmd_pid;
	return (ft_free_split(envp), RET_OK);
}
