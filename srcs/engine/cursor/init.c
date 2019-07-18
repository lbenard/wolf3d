/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:45:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/12 23:49:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "ft/mem.h"

t_result	init_cursor(t_cursor *const self)
{
	ft_bzero(&self->custom_cursor, sizeof(t_frame));
	self->is_custom = FALSE;
	self->is_visible = TRUE;
	return (OK);
}