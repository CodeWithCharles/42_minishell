/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:27:30 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/11 17:45:40 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	write_here_doc_to_file(
	t_minishell_ctx *ctx,
	const char *delimiter
)
{
	char	*line;
	int		doc_fd;

	doc_fd = open(TMP_HERE_DOC_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (doc_fd == INVALID_FD)
		return (print_gen_error(ctx, ERR_COULD_NOT_OPEN_HD), RET_ERR);
	line = NULL;
	while (1)
	{
		line = readline(HERE_DOC_PREFIX);
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(doc_fd, line, ft_strlen(line));
		write(doc_fd, "\n", 1);
		free(line);
	}
	close(doc_fd);
	return (RET_OK);
}

void	handle_here_doc(
	t_minishell_ctx *ctx,
	t_cmd *cmd
)
{
	t_redir	*last_redir;

	last_redir = ft_lastredir(cmd->redir_in_list);
	if (!last_redir->file)
		return (print_gen_error(ctx, ERR_NO_HD_DELIMITER));
	if (write_here_doc_to_file(ctx, last_redir->file) == -1)
		return (print_gen_error(ctx, ERR_WRITE_TO_HERE_DOC));
	cmd->fd_in = open(TMP_HERE_DOC_PATH, O_RDONLY, 0644);
	if (cmd->fd_in == -1)
		return (print_gen_error(ctx, ERR_READ_HERE_DOC));
}
