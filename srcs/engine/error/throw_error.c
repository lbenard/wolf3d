/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:22:50 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 20:20:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "engine/error.h"

void	*throw_error(void)
{
	if (errno)
		perror(PROGRAM_NAME);
	errno = 0;
	return (NULL);
}