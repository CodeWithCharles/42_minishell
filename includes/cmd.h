/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:25 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 16:43:24 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"

typedef enum e_file_type
{
	REDIR_NONE,
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_EMPTY,
}	t_redir_type;

typedef struct s_redir
{
	char			*file;
	t_redir_type	type;
}	t_redir;

typedef struct s_cmd
{
	char			*cmd_name;
	char			**cmd_args;
	t_redir			redir_in;
	t_redir			redir_out;
	int				fd_in;
	int				fd_out;
	int				exit_code;
}	t_cmd;

typedef struct s_executing_ctx
{
	int	*pids;
	int	curr_idx;
	int	cmd_count;
	int	(*pipes)[2];
	int	fd_empty;
}	t_executing_ctx;

#endif
