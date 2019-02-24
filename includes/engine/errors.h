/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:30:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/23 17:53:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "types.h"

# define PROGRAM_NAME "wolf3d"

void		*throw_error(void);
void		*throw_error_str(const char *cause);
t_result	throw_result(void);
t_result	throw_result_str(const char *cause);
void		*throw_error_errno(int err);

#endif
