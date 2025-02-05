/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:01 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/31 19:39:08 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define INVALID_FD				-1
# define RET_OK					0
# define RET_ERR				1

# define CODE_CMD_NOT_FOUND			127
# define CODE_CMD_NOT_EXECUTABLE	126
# define CODE_CANNOT_ALLOC			12
# define CODE_EXEC_FAILED			256

# define ERR_TOO_MANY_ARGS		"%s%s:\tToo many arguments.\n%s"
# define ERR_INT_ERR_ALLOC		"%s%s:\tInternal alloc error.\n%s"
# define ERR_ARG_MUST_BE_INT	"%s%s:\t%s\t: must be an int.\n%s"
# define ERR_CMD_NOT_FOUND		"%s%s:\tCommand not found.\n%s"
# define ERR_COULD_NOT_OPEN_IN	"%s%s:\tCould not open infile.\n%s"
# define ERR_COULD_NOT_OPEN_EMP "%s%s:\tCould not open empty file.\n%s"
# define ERR_COULD_NOT_OPEN_OUT	"%s%s:\tCould not open outfile.\n%s"
# define ERR_COULD_NOT_OPEN_HD	"%s%s:\tCould not open here-doc's tmp file.\n%s"
# define ERR_CMD_NOT_EXECUTABLE	"%s%s:\tCommand not executable : %s.\n%s"
# define ERR_PIPING				"%s%s:\tError creating pipe.\n%s"
# define ERR_WAITPID			"%s%s:\tWait pid fatal exception.\n%s"
# define ERR_NO_HD_DELIMITER	"%s%s:\tNo delimiter provided for here-doc.\n%s"
# define ERR_WRITE_TO_HERE_DOC	"%s%s:\tError writting here_doc to file.\n%s"
# define ERR_READ_HERE_DOC		"%s%s:\tError re-opening here_doc.\n%s"

# define ERR_PWD_CUR_DIR "%s%s:\t%s\t: error retrieving current dir : %s.\n%s"

# define ERR_CD_HOME_NOT_SET	"%s%s:\t%s\t: home not set.\n%s"

#endif
