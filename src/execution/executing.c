/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:16:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/05 11:29:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	_custom_exit(
	t_executing_ctx *exec_ctx,
	char **envp,
	int exit_code
)
{
	clean_exec_ctx(exec_ctx);
	if (envp)
		ft_free_split(envp);
	if (ft_envp(NULL))
		ft_lstclear(ft_envp(NULL), free);
	exit(exit_code);
}

static void	execute_external(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd *cmd,
	char **envp
)
{
	get_cmd(ctx, cmd);
	if (cmd->exit_code == CODE_CMD_NOT_FOUND)
		_custom_exit(exec_ctx, envp, CODE_CMD_NOT_FOUND);
	if (execve(cmd->cmd_name, cmd->cmd_args, envp) == -1)
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		_custom_exit(exec_ctx, envp, CODE_CMD_NOT_EXECUTABLE);
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
		ft_exit(ctx, exec_ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "echo") == 0)
		ft_echo(ctx, cmd->cmd_args);
	else
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		_custom_exit(exec_ctx, envp, CODE_CMD_NOT_EXECUTABLE);
	}
	_custom_exit(exec_ctx, envp, RET_OK);
}

int	fork_command(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	t_executing_ctx *exec_ctx,
	int p_fd[2]
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
		if (setup_redirections(ctx, exec_ctx, cmd, p_fd) == RET_ERR)
			_custom_exit(exec_ctx, envp, RET_ERR);
		if (is_valid_builtin(cmd->cmd_name))
			execute_builtin(ctx, exec_ctx, cmd, envp);
		else
			execute_external(ctx, exec_ctx, cmd, envp);
	}
	if (exec_ctx->last_fd != INVALID_FD)
		close(exec_ctx->last_fd);
	if (exec_ctx->cmd_list[exec_ctx->curr_idx + 1] != NULL)
		exec_ctx->last_fd = p_fd[0];
	else
		close(p_fd[0]);
	return (close(p_fd[1]), ft_free_split(envp), RET_OK);
}
