/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/15 20:58:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/error.h"

void	background_frame(t_frame *frame, t_rgb ground_color,
	t_rgb sky_color)
{
	t_usize	i;
	float	darkness;

	i = ft_usize(0, 0);
	while (i.y < frame->size.y)
	{
		i.x = 0;
		while (i.x < frame->size.x)
		{
			darkness = (((double)frame->size.y / 2.0f) - (double)i.y);
			if (i.y < frame->size.y / 2)
				darkness /= ((double)frame->size.y / 2.0f);
			else
				darkness /= (((double)frame->size.y / 2.0f)
					- ((double)frame->size.y));
			if (i.y < frame->size.y / 2)
				frame->frame[i.y * frame->size.x + i.x] =
					rgb_to_int(ft_rgb(ground_color.r * darkness, ground_color.g
					* darkness, ground_color.b * darkness));
			else
				frame->frame[i.y * frame->size.x + i.x] =
					rgb_to_int(ft_rgb(sky_color.r * darkness, sky_color.g
					* darkness, sky_color.b * darkness));
			i.x++;
		}
		i.y++;
	}
}

t_raycasting_scene	*new_raycasting_scene(const t_window *const window)
{
	t_raycasting_scene	*ret;

	if (!(ret = (t_raycasting_scene*)malloc(sizeof(t_raycasting_scene))))
		return (throw_error_str("Failed while mallocing raycasting scene"));
	if (!init_scene(&ret->super, RAYCASTING_SCENE_TYPE, "Raycasting sandbox"))
	{
		free(ret);
		return (throw_error_str("Failed while initalizing scene"));
	}
	if (init_map(&ret->map, "maps/simple_map.wolf") == ERROR)
	{
		free(ret);
		return (throw_error_str("Failed while initializing map"));
	}
	if (init_frame(&ret->background, window->size, ft_rgba(255, 255, 255, 255))
		== ERROR)
	{
		free(ret);
		destroy_map(&ret->map);
		return (throw_error_str("Failed while initializing frame"));
	}
	ret->ground_color = ft_rgb(235, 206, 135);
	ret->sky_color = ft_rgb(96, 128, 56);
	background_frame(&ret->background, ret->ground_color, ret->sky_color);
	if (init_raycasting_renderer(&ret->renderer, window->size, &ret->map) ==
		ERROR)
	{
		free(ret);
		destroy_map(&ret->map);
		return (throw_error_str("Failed while initializing raycasting "
			"renderer"));
	}
	if (!(ret->texture = sfImage_createFromFile("wall.png")))
	{
		free(ret);
		destroy_map(&ret->map);
		destroy_raycasting_renderer(&ret->renderer);
		return (throw_error_str("Failed while initializing texture"));
	}
	ret->player_ref = new_player_entity();
	if (scene_add_entity(&ret->super,
		new_entity_node((t_entity*)ret->player_ref)) == ERROR)
	{
		free(ret);
		destroy_map(&ret->map);
		destroy_raycasting_renderer(&ret->renderer);
		sfImage_destroy(ret->texture);
		return (throw_error_str("Failed while initializing player entity"));
	}
	ret->player_ref->super.transform.position = ft_vec3f(ret->renderer.position.x, ret->renderer.position.y, 0);
	event_handler_add_sub_handler(&ret->super.input_manager,
		&ret->player_ref->event_handler);
	return (ret);
}