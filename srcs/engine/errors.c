/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:30:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/23 21:27:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "engine/errors.h"
#include "ft/io.h"
#include "types.h"

void		*throw_error(void)
{
	if (errno)
		perror(PROGRAM_NAME);
	errno = 0;
	return (NULL);
}

void		*throw_error_str(const char *cause)
{
	if (cause)
	{
		ft_putstr(PROGRAM_NAME ": ");
		ft_putstr(cause);
		ft_putchar('\n');
	}
	return (NULL);
}

t_result	throw_result(void)
{
	throw_error();
	return (ERROR);
}

t_result	throw_result_str(const char *cause)
{
	throw_error_str(cause);
	return (ERROR);
}

void		*throw_error_errno(int err)
{
	if (err)
	{
		errno = err;
		perror(PROGRAM_NAME);
	}
	return (NULL);
}
