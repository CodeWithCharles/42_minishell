/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:25 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/11 16:22:57 by jcheron          ###   ########.fr       */
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
	WORD,
	PIPE
}	t_redir_type;

typedef struct s_redir
{
	char			*file;
	t_redir_type	type;
}	t_redir;

typedef struct s_redir_node
{
	t_redir				redir;
	struct s_redir_node	*next;
}	t_redir_node;


typedef struct s_cmd
{
	char			*cmd_name;
	char			**cmd_args;
	t_redir_node	*redir_in_list;
	t_redir_node	*redir_out_list;
	t_redir			redir_out;
	int				fd_in;
	int				fd_out;
	int				exit_code;
}	t_cmd;

typedef struct s_token
{
	t_redir_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_parser
{
	t_cmd	**cmds;
	size_t	cmd_count;
	size_t	args_count;
}	t_parser;

typedef struct s_executing_ctx
{
	int		curr_idx;
	int		cmd_count;
	int		last_fd;
	int		fd_empty;
	t_cmd	**cmd_list;
}	t_executing_ctx;

#endif
