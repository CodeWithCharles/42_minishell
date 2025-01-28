/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:39 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/28 16:32:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
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
	ctx.envp = init_env(envp);
	while (1)
	{
		prompt_message = build_prompt_message(&ctx);
		input = readline(prompt_message);
		free(prompt_message);
		add_history(input);
	}
	return (0);
}
