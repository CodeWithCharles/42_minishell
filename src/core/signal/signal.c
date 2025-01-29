/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:14:22 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 10:21:05 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static void	handle_signals(
				int signal
				);

// Header implementations

int	is_any_command_active(
	int is_it
)
{
	static int	value = 0;

	if (is_it >= 0)
		value = is_it;
	return (value);
}

void	setup_signals(void)
{
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, handle_signals);
}

// Static implementations

static void	handle_signals(
	int signal
)
{
	if (signal == SIGINT)
	{
		if (is_any_command_active(-1))
			ft_putchar_fd('\n', STDOUT_FILENO);
		else
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			rl_on_new_line();
			rl_replace_line("", STDIN_FILENO);
			rl_redisplay();
		}
	}
	else if (signal == SIGQUIT)
		ft_putstr_fd("\b\b \b  \b\b", STDOUT_FILENO);
}
