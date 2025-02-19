/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:00:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/19 19:06:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static int	check_pipe_in_between(
				const char *input);

// Header implementations

void	handle_parse_error(
	t_minishell_ctx *ctx,
	const char *error,
	t_list **tokens
)
{
	print_gen_error(ctx, error);
	if (tokens)
		ft_lstclear(tokens, free_token);
}

int	check_invalid_pipe(
	const char *input
)
{
	int	i;

	i = 0;
	while (input[i] && (ft_isspace(input[i])
			|| input[i] == '>' || input[i] == '<'))
		i++;
	if (input[i] == '|')
		return (RET_ERR);
	i = ft_strlen(input) - 1;
	while (i >= 0 && input[i] && (ft_isspace(input[i])
			|| input[i] == '>' || input[i] == '<'))
		i--;
	if (i >= 0 && input[i] == '|')
		return (RET_ERR);
	return (check_pipe_in_between(input));
}

// Static implementations

static int	has_only_spaces_between(
	char *start,
	char *end
)
{
	while (start != end)
	{
		if (ft_isalnum(*start))
			return (RET_OK);
		start++;
	}
	return (RET_ERR);
}

static int	check_pipe_in_between(
	const char *input
)
{
	char	*f_pipe;
	char	*n_pipe;

	f_pipe = ft_strchr(input, '|');
	while (f_pipe)
	{
		n_pipe = ft_strchr(f_pipe + 1, '|');
		if (!n_pipe)
			return (RET_OK);
		if (has_only_spaces_between(f_pipe + 1, n_pipe) == RET_ERR)
			return (RET_ERR);
		f_pipe = n_pipe;
	}
	return (RET_OK);
}
