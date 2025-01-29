/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:25 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 12:18:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"

typedef enum e_control
{
	CONTROL_NONE,
	CONTROL_AND,
	CONTROL_OR,
}	t_control;

typedef struct s_cmd_list
{
	t_control	control;
	t_list		*cmd;
}	t_cmd_list;

typedef enum e_file_type
{
	FILE_INPUT,
	FILE_OUTPUT,
	FILE_APPEND,
	FILE_HEREDOC,
}	t_file_type;

typedef struct s_file
{
	char		*name;
	t_file_type	type;
}	t_file;

typedef struct s_cmd
{
	char	**argv;
	t_list	*files_in;
	t_list	*files_out;
	int		fd_in;
	int		fd_out;
	int		exit_code;
	pid_t	pid;
}	t_cmd;

#endif
