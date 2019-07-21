/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_custom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:47:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/21 16:54:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"

static void	crosshair_cursor(t_cursor *const self)
{
	t_usize	i;
	t_usize	cursor_size;

	cursor_size = self->custom_cursor.size;
	i = ft_usize(0, 0);
	while (i.x < self->custom_cursor.size.x)
		self->custom_cursor.frame[cursor_size.x * (cursor_size.y / 2) + i.x++]
			= ft_rgba(255, 255, 255, 255).integer;
	while (i.y < self->custom_cursor.size.y)
		self->custom_cursor.frame[cursor_size.x * i.y++ - (cursor_size.x / 2)]
			= ft_rgba(255, 255, 255, 255).integer;
}

t_result	init_cursor_custom(t_cursor *const self, const t_usize cursor_size)
{
	init_cursor(self);
	if (init_frame(&self->custom_cursor, cursor_size, ft_rgba(0, 0, 0, 0))
		== ERROR)
		return (throw_result_str("Error while creating cursor's frame"));
	crosshair_cursor(self);
	self->is_custom = TRUE;
	return (OK);
}