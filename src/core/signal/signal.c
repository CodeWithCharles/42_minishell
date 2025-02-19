/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:14:22 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 12:17:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

volatile int	g_signal = 0;

// Static prototypes

static void	_sig_handler_interactive(
				int signal);

static void	_sig_handler_executing(
				int signal);

// Header implementations

void	set_sig_interactive(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, _sig_handler_interactive);
}

void	set_sig_executing(void)
{
	signal(SIGQUIT, _sig_handler_executing);
	signal(SIGINT, _sig_handler_executing);
}

// Static implementations

static void	_sig_handler_interactive(
	int signal
)
{
	if (signal == SIGINT)
		g_signal = 130;
	else
		g_signal = signal;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	_sig_handler_executing(
	int signal
)
{
	if (signal == SIGQUIT)
	{
		g_signal = 0;
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
	}
	else if (signal == SIGINT)
	{
		g_signal = 130;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
		g_signal = signal;
}
