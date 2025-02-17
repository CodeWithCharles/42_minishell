/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:16:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/17 17:42:03 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	increase_env_shlvl(void)
{
	char	*tmp_shlvl;
	char	*tmp_env_shlvl;

	tmp_env_shlvl = ft_getenv("SHLVL=");
	tmp_shlvl = ft_itoa(ft_atoi(tmp_env_shlvl) + 1);
	free(tmp_env_shlvl);
	tmp_env_shlvl = ft_to_env_format("SHLVL", tmp_shlvl);
	free(tmp_shlvl);
	ft_setenv(tmp_env_shlvl);
	free(tmp_env_shlvl);
}

void	custom_exit(
	t_executing_ctx *exec_ctx,
	char **envp,
	int update_exit_code,
	int exit_code
)
{
	clean_after_exec(exec_ctx, envp);
	if (update_exit_code && exit_code != -1)
		ft_last_exit_code(exit_code);
	if (exit_code != -1)
		exit(exit_code);
}

static void	execute_external(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd *cmd
)
{
	char	**envp;

	increase_env_shlvl();
	if (ft_envp_tab(&envp) == RET_ERR)
		custom_exit(exec_ctx, NULL, 0, 1);
	get_cmd(ctx, cmd);
	if (cmd->exit_code == CODE_CMD_NOT_FOUND)
		custom_exit(exec_ctx, envp, 0, CODE_CMD_NOT_FOUND);
	if (execve(cmd->cmd_name, cmd->cmd_args, envp) == -1)
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		custom_exit(exec_ctx, envp, 0, CODE_CMD_NOT_EXECUTABLE);
	}
	custom_exit(exec_ctx, envp, 0, 0);
}

void	execute_builtin(
	t_minishell_ctx *ctx,
	t_executing_ctx *exec_ctx,
	t_cmd *cmd,
	int should_exit
)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp(cmd->cmd_name, "cd") == 0)
		exit_code = ft_cd(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "pwd") == 0)
		exit_code = ft_pwd(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "env") == 0)
		exit_code = ft_env(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "export") == 0)
		exit_code = ft_export(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "unset") == 0)
		exit_code = ft_unset(ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "exit") == 0)
		ft_exit(ctx, exec_ctx, cmd->cmd_args);
	else if (ft_strcmp(cmd->cmd_name, "echo") == 0)
		exit_code = ft_echo(ctx, cmd->cmd_args);
	else
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		exit_code = CODE_CMD_NOT_FOUND;
	}
	if (should_exit)
		custom_exit(exec_ctx, NULL, 0, exit_code);
	ft_last_exit_code(exit_code);
}

int	fork_command(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	t_executing_ctx *exec_ctx,
	int p_fd[2]
)
{
	int		cmd_pid;

	cmd_pid = fork();
	if (cmd_pid == -1)
		return (RET_ERR);
	if (cmd_pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (setup_redirections(exec_ctx, cmd, p_fd) == RET_ERR)
			custom_exit(exec_ctx, NULL, 0, RET_ERR);
		if (is_valid_builtin(cmd->cmd_name))
			execute_builtin(ctx, exec_ctx, cmd, 1);
		else
			execute_external(ctx, exec_ctx, cmd);
	}
	if (exec_ctx->last_fd != INVALID_FD)
		close(exec_ctx->last_fd);
	if (exec_ctx->curr_idx + 1 < exec_ctx->cmd_count)
		exec_ctx->last_fd = p_fd[0];
	else
		close(p_fd[0]);
	return (close(p_fd[1]), RET_OK);
}
