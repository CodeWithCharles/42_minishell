/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:25 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 09:58:21 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"

typedef enum e_file_type
{
	FILE_INPUT,
	FILE_OUTPUT,
	FILE_APPEND,
	FILE_HEREDOC,
	FILE_NO_REDIRECT,
}	t_file_type;

typedef struct s_file
{
	char		*name;
	t_file_type	type;
}	t_file;

typedef struct s_cmd
{
	t_file_type	type;
	char		*cmd_name;
	char		**cmd_args;
	int			fd_infile;
	int			fd_outfile;
	int			fd_in;
	int			fd_out;
	int			exit_code;
}	t_cmd;

#endif
