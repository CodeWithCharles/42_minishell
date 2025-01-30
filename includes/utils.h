/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:54 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/30 17:00:06 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Functions

void	ft_free_split(
			char **split);

char	**spooq(
			char *str,
			char sep);

char	*ft_strtok_quotes(char *str, char sep);

int		ft_last_exit_code(
			int exit_code);

void	ft_lstremove(
			t_list **lst,
			void (*del)()
			);

char	*ft_which(
			const char	*cmd
			);

#endif
