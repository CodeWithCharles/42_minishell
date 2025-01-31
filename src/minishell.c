/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:39 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 12:40:11 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	t_should_continue	handle_input(
	char *input,
	t_minishell_ctx *ctx,
	t_should_free should_free
)
{
	char	**argv;

	if (input == NULL)
		return (ft_putchar_fd('\n', 1), SHOULD_NOT_CONTINUE);
	if (ft_strlen(input) == 0)
		return (free(input), SHOULD_CONTINUE);
	argv = spooq(input, ' ');
	if (!argv)
		return (free(input), SHOULD_NOT_CONTINUE);
	int i = 0;
	while (argv[i] != NULL)
	{
		// Appliquer l'expansion des variables sur chaque argument
		char *expanded_arg = expand_variables_in_input(ctx, argv[i]);
		free(argv[i]);  // Libérer l'ancien argument
		argv[i] = expanded_arg;  // Remplacer par l'argument expansé
		i++;
	}
	add_history(input);
	if (execute_builtin(ctx, argv))
	{
		ft_free_split(argv);
		if (should_free)
			free(input);
		return (SHOULD_CONTINUE);
	}
	if (should_free)
		free(input);
	ft_free_split(argv);
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
