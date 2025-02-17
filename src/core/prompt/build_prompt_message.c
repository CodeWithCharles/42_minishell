/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt_message.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:24:43 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/13 13:57:14 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static char	*process_current_dir(void);

// Header implementations

char	*build_prompt_message(
	t_minishell_ctx *ctx
)
{
	char	*message;
	char	*tmp;

	tmp = get_term_color(COLOR_BLACK, COLOR_GRAY);
	message = ft_strdup(tmp);
	free(tmp);
	ft_strcat(&message, ctx->p_name);
	ft_strcat(&message, ":");
	tmp = get_term_color(COLOR_YELLOW, COLOR_CYAN);
	ft_strcat(&message, tmp);
	free(tmp);
	tmp = process_current_dir();
	ft_strcat(&message, tmp);
	free(tmp);
	ft_strcat(&message, " >"TERM_RESET" ");
	return (message);
}

// Static implementations

static char	*process_current_dir(void)
{
	char	*cwd;
	char	*home;
	char	*shortened;
	int		new_len;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	home = ft_getenv("HOME");
	if (home && ft_strncmp(cwd, home, ft_strlen(home)) == 0)
	{
		new_len = ft_strlen(cwd) - ft_strlen(home) + 2;
		shortened = malloc(ft_strlen(cwd) - ft_strlen(home) + 2);
		if (!shortened)
			return (free(cwd), free(home), NULL);
		shortened[0] = '~';
		ft_strlcpy(shortened + 1, cwd + ft_strlen(home), new_len - 1);
		free(cwd);
		free(home);
		home = NULL;
		return (shortened);
	}
	if (home)
		free(home);
	return (cwd);
}
