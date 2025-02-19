/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:59:35 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/18 09:14:19 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Static prototypes

static bool	_is_executable(
				char *path
				);

static char	*_join_cmd_path(
				const char *cmd,
				size_t cmd_len,
				const char **path
				);

static char	*_find_cmd_path(
				const char *cmd,
				const char *path
				);

// Header implementations

char	*ft_which(
	const char *cmd
)
{
	char		*path;
	char		*cmd_path;

	cmd_path = ft_strdup(cmd);
	if (!cmd_path)
		return (NULL);
	if (!_is_executable(cmd_path))
	{
		free(cmd_path);
		cmd_path = NULL;
		if (ft_strncmp(cmd, "./", 2))
		{
			path = ft_getenv("PATH");
			if (!path)
				return (NULL);
			path += 4;
			cmd_path = _find_cmd_path(cmd, path);
			free(path - 4);
		}
	}
	return (cmd_path);
}

// Static implementations

static bool	_is_executable(
	char *path
)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (!access(path, X_OK) && S_ISREG(path_stat.st_mode));
}

static char	*_join_cmd_path(
	const char *cmd,
	size_t cmd_len,
	const char **path
)
{
	char	*cmd_path;
	size_t	path_len;

	path_len = 0;
	while ((*path)[path_len] && (*path)[path_len] != ':')
		path_len++;
	cmd_path = malloc(cmd_len + path_len + 2);
	if (!cmd_path)
		return (NULL);
	ft_strlcpy(cmd_path, *path, path_len + 1);
	cmd_path[path_len] = '/';
	ft_strlcpy(cmd_path + path_len + 1, cmd, cmd_len + 1);
	(*path) += path_len;
	return (cmd_path);
}

static char	*_find_cmd_path(
	const char *cmd,
	const char *path
)
{
	size_t	cmd_len;
	char	*cmd_path;

	cmd_path = NULL;
	cmd_len = ft_strlen(cmd);
	while (*path)
	{
		path++;
		cmd_path = _join_cmd_path(cmd, cmd_len, &path);
		if (!cmd_path)
			return (NULL);
		if (_is_executable(cmd_path))
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}
