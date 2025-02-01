/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:39 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/01 10:41:32 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static	t_should_continue	handle_input(
// 	char *input,
// 	t_minishell_ctx *ctx,
// 	t_should_free should_free
// )
// {
// 	char	**argv;

// 	(void)ctx;
// 	if (input == NULL)
// 		return (ft_putchar_fd('\n', 1), SHOULD_NOT_CONTINUE);
// 	if (ft_strlen(input) == 0)
// 		return (free(input), SHOULD_CONTINUE);
// 	argv = spooq(input, ' ');
// 	if (!argv)
// 		return (free(input), SHOULD_NOT_CONTINUE);
// 	int i = 0;
// 	fd_printf(STDOUT_FILENO, "input: %s\n", input);
// 	while (argv[i] != NULL)
// 	{
// 		char *expanded_arg = expand_variables_in_input(ctx, argv[i]);
// 		free(argv[i]);
// 		argv[i] = expanded_arg;
// 		fd_printf(STDOUT_FILENO, "argv[%d]: %s\n", i, argv[i]);
// 		i++;
// 	}
// 	add_history(input);
// 	/*if (execute_builtin(ctx, argv))
// 	{
// 		ft_free_split(argv);
// 		if (should_free)
// 			free(input);
// 		return (SHOULD_CONTINUE);
// 	}*/
// 	if (should_free)
// 		free(input);
// 	ft_free_split(argv);
// 	return (SHOULD_CONTINUE);
// }

static	t_should_continue	handle_input(
	char *input,
	t_minishell_ctx *ctx,
	t_should_free should_free
)
{
	t_cmd	*cmds;

	(void)ctx;
	if (input == NULL)
		return (ft_putchar_fd('\n', 1), SHOULD_NOT_CONTINUE);
	if (ft_strlen(input) == 0)
		return (free(input), SHOULD_CONTINUE);
	cmds = parse_commands(ctx, input);
	if (!cmds)
		return (free(input), SHOULD_NOT_CONTINUE);
	int i = 0;
	fd_printf(STDOUT_FILENO, "input: %s\n", input);
	while (cmds[i].cmd_name)
	{
		fd_printf(STDOUT_FILENO, "cmd_name: %s\n", cmds[i].cmd_name);
		int j = 0;
		while (cmds[i].cmd_args[j])
		{
			fd_printf(STDOUT_FILENO, "cmd_args[%d]: %s\n", j, cmds[i].cmd_args[j]);
			fd_printf(STDOUT_FILENO, "cmd_args[%d] expanded: %s\n", j, expand_variables_in_input(ctx, cmds[i].cmd_args[j]));
			j++;
		}
		fd_printf(STDOUT_FILENO, "cmd_redirect_in_type: %d\n", cmds[i].redir_in.type);
		fd_printf(STDOUT_FILENO, "cmd_redirect_in_file: %s\n", cmds[i].redir_in.file);
		fd_printf(STDOUT_FILENO, "cmd_redirect_out_type: %d\n", cmds[i].redir_out.type);
		fd_printf(STDOUT_FILENO, "cmd_redirect_out_file: %s\n", cmds[i].redir_out.file);
		i++;
	}
	add_history(input);
	/*if (execute_builtin(ctx, argv))
	{
		ft_free_split(argv);
		if (should_free)
			free(input);
		return (SHOULD_CONTINUE);
	}*/
	if (should_free)
		free(input);
	// ft_free_split(argv);
	return (SHOULD_CONTINUE);
}

int	main(
	int argc,
	char **argv,
	char **envp
)
{
	t_minishell_ctx	ctx;
	char			*prompt_message;
	char			*input;

	ctx = (t_minishell_ctx){};
	if (ft_strncmp(argv[0], "./", 2) == 0)
		argv[0] = argv[0] + 2;
	ctx.p_name = argv[0];
	if (argc > 1)
		return (print_gen_error(&ctx, ERR_TOO_MANY_ARGS), 0);
	ft_envp(envp);
	setup_signals();
	while (1)
	{
		prompt_message = build_prompt_message(&ctx);
		if (!prompt_message)
			return (print_gen_error(&ctx, ERR_INT_ERR_ALLOC), 0);
		input = readline(prompt_message);
		free(prompt_message);
		if (!handle_input(input, &ctx, SHOULD_FREE))
			break ;
	}
	return (0);
}
