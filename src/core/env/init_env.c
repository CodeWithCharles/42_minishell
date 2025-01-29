/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:23:24 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 11:10:06 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static t_env_var	*parse_to_env_var(
						char *envp_var
						);

// Header implementations

t_list	*init_env(
	char **envp
)
{
	t_list	*start;

	start = NULL;
	if (*envp)
		start = ft_lstnew(parse_to_env_var(*envp++));
	if (start)
		while (*envp)
			ft_lstadd_back(&start, ft_lstnew(parse_to_env_var(*envp++)));
	return (start);
}

// Static implementations

t_env_var	*parse_to_env_var(
	char *envp_var
)
{
	t_env_var	*env_var;
	char		*equal_pos;

	if (envp_var)
	{
		env_var = malloc(sizeof(t_env_var));
		if (!env_var)
			return (NULL);
		equal_pos = ft_strchr(envp_var, '=');
		equal_pos[0] = '\0';
		env_var->var_name = ft_strdup(envp_var);
		equal_pos++;
		env_var->value = ft_strdup(equal_pos);
		return (env_var);
	}
	return (NULL);
}
