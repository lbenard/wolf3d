/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_errno.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:25:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 20:20:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "engine/error.h"

void		*throw_error_errno(const int err)
{
	if (err)
	{
		errno = err;
		perror(PROGRAM_NAME);
	}
	return (NULL);
}