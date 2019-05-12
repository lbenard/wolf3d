/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:07:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 18:23:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/delta.h"
#include "game/scenes/scene_type.h"

#include <stdio.h>

void	game_loop(t_game *self)
{
	double	last_time;
	sfEvent	event;

	last_time = get_wall_time();
	while (sfRenderWindow_pollEvent(self->window, &event))
		event_handler_call(&self->event_handler, &event);
	scene_type_update(self->scene, get_last_delta());
	if (game_is_focused(self))
	{
		scene_type_render(self->scene, &self->window_framebuffer);
		framebuffer_update(&self->window_framebuffer);
		framebuffer_display(&self->window_framebuffer, self->window);
	}
	// list_foreach(&self->scene->entities, 0, print_entity);
	double spf = get_wall_time() - last_time;
	printf("fps %f\n", 1.0f / spf);
	set_last_delta(spf);
	last_time = get_wall_time();
}