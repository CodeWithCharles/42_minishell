/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:27:30 by cpoulain          #+#    #+#             */
/*   Updated: 2025/02/12 12:29:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	get_here_doc_tmp_path(
	t_redir **redir
)
{
	static int	idx = 0;
	char		*idx_str;

	free((*redir)->file);
	idx_str = ft_itoa(idx);
	(*redir)->file = ft_strjoin(TMP_HERE_DOC_PATH, idx_str);
	free(idx_str);
	idx++;
}

static int	write_here_doc_to_file(
	t_minishell_ctx *ctx,
	t_redir **redir,
	const char *delimiter
)
{
	char	*line;
	int		doc_fd;

	get_here_doc_tmp_path(redir);
	doc_fd = open((*redir)->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

int	handle_here_doc(
	t_minishell_ctx *ctx,
	t_redir **redir
)
{
	int	tmp_fd;

	tmp_fd = -1;
	if (!(*redir)->file)
		return (print_gen_error(ctx, ERR_NO_HD_DELIMITER), RET_ERR);
	if (write_here_doc_to_file(ctx, redir, (*redir)->file) == RET_ERR)
		return (print_gen_error(ctx, ERR_WRITE_TO_HERE_DOC), RET_ERR);
	tmp_fd = open((*redir)->file, O_RDONLY, 0644);
	if (tmp_fd == -1)
		return (print_gen_error(ctx, ERR_READ_HERE_DOC), RET_ERR);
	else
		return (close(tmp_fd), RET_OK);
}
