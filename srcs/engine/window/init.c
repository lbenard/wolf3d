/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/19 18:48:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	init_window(t_window *const self, const char *const name,
				t_usize size)
{
	sfVideoMode	mode;

	mode = (sfVideoMode) {.width = size.x, .height = size.y,
		.bitsPerPixel = 32};
	if (!(*(sfRenderWindow**)&self->window = sfRenderWindow_create(mode,
		name, sfClose, NULL)))
		return (throw_result_str("Error while create sfRenderWindow"));
	if (init_frame(&self->frame, size, ft_rgba(0, 0, 0, 255)) == ERROR)
	{
		sfRenderWindow_destroy(self->window);
		return (throw_result_str("Error while creating window's frame"));
	}
	if (init_cursor_custom(&self->cursor, ft_usize(32, 32)) == ERROR)
	{
		sfRenderWindow_destroy(self->window);
		destroy_frame(&self->frame);
		return (throw_result_str("Failed while creating window's cursor"));
	}
	self->name = ft_strdup(name);
	*(t_usize*)&self->size = size;
	return (OK);
}