/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:02:55 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 17:04:11 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

// Minishell context

typedef struct s_minishell_ctx
{
	t_list	*envp;
	char	*p_name;
}	t_minishell_ctx;

#endif
