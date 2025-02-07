/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:04:07 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/07 19:05:00 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_last_directory(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len == 0)
		return ;
	while (len > 0 && path[len] != '/')
		len--;
	path[len] = '\0';
	if (ft_strlen(path) == 0)
	{
		path[len] = '/';
		path[len + 1] = '\0';
	}
}

static void	append_directory(char **abs_path, char *dir)
{
	ft_strcat(abs_path, "/");
	ft_strcat(abs_path, dir);
}

static void	process_path_parts(char **abs_path, char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (ft_strcmp(parts[i], "..") == 0)
			remove_last_directory(*abs_path);
		else if (ft_strcmp(parts[i], ".") != 0)
		{
			append_directory(abs_path, parts[i]);
			if (!*abs_path)
				break ;
		}
		free(parts[i++]);
	}
	free(parts);
}

char	*ft_realpath(
	const char *relative_path
)
{
	char	*abs_path;
	char	**parts;

	abs_path = getcwd(NULL, 0);
	if (!abs_path)
		return (NULL);
	parts = ft_split(relative_path, '/');
	if (!parts)
		return (free(abs_path), NULL);
	process_path_parts(&abs_path, parts);
	if (!*abs_path)
		return (NULL);
	return (abs_path);
}
