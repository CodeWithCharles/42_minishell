/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:39 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 12:13:29 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	t_should_continue	handle_input(
	char *input,
	t_minishell_ctx *ctx,
	t_should_free should_free
)
{
	t_cmd	**cmds;
	t_list	*tokens;

	(void)ctx;
	if (input == NULL)
		return (ft_putstr_fd("exit\n", STDOUT_FILENO), SHOULD_NOT_CONTINUE);
	if (ft_strlen(input) == 0)
		return (free(input), SHOULD_CONTINUE);
	add_history(input);
	tokens = tokenize(ctx, input);
	if (!tokens)
		return (free(input), SHOULD_CONTINUE);
	cmds = parse_tokens(tokens);
	if (tokens)
		ft_lstclear(&tokens, free_token);
	if (!cmds)
		return (free(input), SHOULD_NOT_CONTINUE);
	if (should_free)
		free(input);
	execute_pipeline(ctx, cmds);
	if (cmds)
		ft_free_cmd_list(&cmds, ft_cmd_count(cmds));
	return (SHOULD_CONTINUE);
}

static char	*get_exec_name(char *exec_path)
{
	if (ft_strchr(exec_path, '/') != NULL)
		return (ft_strrchr(exec_path, '/') + 1);
	else
		return (exec_path);
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
	ctx.p_name = get_exec_name(argv[0]);
	if (argc > 1)
	{
		ft_lstclear(ft_envp(NULL), free);
		return (print_gen_error(&ctx, ERR_TOO_MANY_ARGS), 0);
	}
	ft_envp(envp);
	while (1)
	{
		set_sig_interactive();
		prompt_message = build_prompt_message(&ctx);
		if (!prompt_message)
			return (print_gen_error(&ctx, ERR_INT_ERR_ALLOC), 0);
		input = readline(prompt_message);
		free(prompt_message);
		if (!handle_input(input, &ctx, SHOULD_FREE))
			break ;
	}
	ft_lstclear(ft_envp(NULL), free);
	return (g_signal);
}
