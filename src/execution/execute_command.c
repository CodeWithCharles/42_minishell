/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:16:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 14:02:27 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	execute_external(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	char **envp
)
{
	char	*cmd_name;

	cmd_name = ft_strdup(cmd->cmd_name);
	if (!cmd_name)
	{
		print_gen_error(ctx, ERR_INT_ERR_ALLOC);
		exit(CODE_CANNOT_ALLOC);
	}
	get_cmd(ctx, cmd);
	if (cmd->exit_code == CODE_CMD_NOT_FOUND)
		exit(CODE_CMD_NOT_FOUND);
	if (cmd->redir_in.type != REDIR_NONE)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->redir_out.type != REDIR_NONE)
		dup2(cmd->fd_out, STDOUT_FILENO);
	if (execve(cmd->cmd_name, cmd->cmd_args, envp) == -1)
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd_name);
		free(cmd_name);
		exit(CODE_CMD_NOT_EXECUTABLE);
	}
	free(cmd_name);
}

static void	execute_builtin(
	t_minishell_ctx *ctx,
	t_cmd *cmd
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
	/*else if (ft_strcmp(cmd->cmd_name, "unset") == 0)
		ft_unset(ctx, cmd->cmd_args);*/
	else if (ft_strcmp(cmd->cmd_name, "exit") == 0)
		ft_exit(ctx, cmd->cmd_args);
	else
	{
		print_arg_error(ctx, ERR_CMD_NOT_EXECUTABLE, cmd->cmd_name);
		exit(CODE_CMD_NOT_EXECUTABLE);
	}
}

int	fork_command(
	t_minishell_ctx *ctx,
	t_cmd *cmd,
	int *pids,
	int index
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
		if (is_valid_builtin(cmd->cmd_name))
			execute_builtin(ctx, cmd);
		else
			execute_external(ctx, cmd, envp);
	}
	else
		pids[index] = cmd_pid;
	return (ft_free_split(envp), RET_OK);
}
