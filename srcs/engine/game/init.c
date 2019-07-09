/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:04:22 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:02:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/error.h"

t_result	init_game(t_game *const self, const char *const name,
	const t_usize window_size)
{
	sfVideoMode	mode;

	mode = (sfVideoMode) {.width = window_size.x, .height = window_size.y,
		.bitsPerPixel = 24};
	if (!(*(sfRenderWindow**)&self->window =
		sfRenderWindow_create(mode, name, sfClose, NULL)))
		return (throw_result_str("Error while creating sfWindow"));
	if (init_frame(&self->window_frame, window_size) == ERROR)
	{
		sfRenderWindow_destroy(self->window);
		return (throw_result_str("Error while creating frame"));
	}
	self->scene = NULL;
	if (init_event_handler(&self->event_handler, self) == ERROR)
	{
		sfRenderWindow_destroy(self->window);
		free_frame(&self->window_frame);
		return (throw_result_str("Error while creating event handler"));
	}
	sfRenderWindow_setMouseCursorVisible(self->window, 0);
	self->window_size = window_size;
	return (OK);
}