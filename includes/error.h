/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:01 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/29 11:43:19 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_TOO_MANY_ARGS		"%s%s:\tToo many arguments.\n%s"
# define ERR_INT_ERR_ALLOC		"%s%s:\tInternal alloc error.\n%s"
# define ERR_ARG_MUST_BE_INT	"%s%s:\t%s\t: must be an int.\n%s"

# define ERR_PWD_CUR_DIR "%s%s:\t%s\t: error retrieving current dir : %s.\n%s"

# define ERR_CD_HOME_NOT_SET	"%s%s:\t%s\t: home not set.\n%s"

#endif
