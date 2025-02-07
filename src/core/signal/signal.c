/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:14:22 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/06 00:31:12 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static void	handle_signals(
				int signal
				);

// Header implementations

void	setup_signals(void)
{
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, SIG_IGN);
}

// Static implementations

static void	handle_signals(
	int signal
)
{
	if (signal == SIGINT)
	{
		if (waitpid(-1, NULL, 0) > 0)
			ft_putchar_fd('\n', STDOUT_FILENO);
		else
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			rl_on_new_line();
			rl_replace_line("", STDIN_FILENO);
			rl_redisplay();
		}
	}
}
