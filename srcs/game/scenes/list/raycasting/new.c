	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/08/14 16:31:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"
#include "engine/image.h"

void	background_frame(t_frame *frame, t_rgb ground_color, t_rgb sky_color)
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
					ft_rgba(sky_color.r * darkness, sky_color.g
					* darkness, sky_color.b * darkness, 255).integer;
			else
				frame->frame[i.y * frame->size.x + i.x] =
					ft_rgba(ground_color.r * darkness, ground_color.g
					* darkness, ground_color.b * darkness, 255).integer;
			i.x++;
		}
		i.y++;
	}
}

t_raycasting_scene	*new_raycasting_scene(
						const t_raycasting_scene_args *const args)
{
	t_raycasting_scene	*ret;

	if (!(ret = (t_raycasting_scene*)malloc(sizeof(t_raycasting_scene))))
		return (throw_error_str("new_raycasting_scene()",
			"failed while mallocing raycasting scene"));
	if (!init_scene(&ret->super, "Raycasting sandbox",
		(void(*)())raycasting_scene_update,
		(void(*)())raycasting_scene_render))
	{
		free(ret);
		return (throw_error_str("new_raycasting_scene()",
			"failed while initalizing scene"));
	}
	module_add_heap_module(&ret->super.module,
		image_from_file("resources/textures/plaster.jpg"),
		(void**)&ret->texture);
	module_add_stack_module(&ret->super.module, map("maps/test_map.wolf"),
		&ret->map);
	module_add_stack_module(&ret->super.module,
		frame(args->window->size, ft_rgba(255, 255, 255, 255)),
		&ret->background);
	module_add_stack_module(&ret->super.module,
		raycasting_renderer(args->window->size, &ret->map), &ret->renderer);
	ret->player_ref = (t_player_entity*)entity_list_add_entity(
		&ret->super.entities, player_entity(&ret->map, ft_vec2f(3.0f, 3.0f)));
	ret->minimap_ref = (t_minimap_entity*)entity_list_add_entity(
		&ret->super.entities,
		minimap_entity(&ret->renderer, ft_usize(200, 200)));
	if (!ret->super.module.has_error)
	{
		ret->ground_color = ft_rgb(105, 105, 105);
		ret->sky_color = ft_rgb(129, 244, 252);
		background_frame(&ret->background, ret->ground_color, ret->sky_color);
		event_handler_add_sub_handler(&ret->super.input_manager,
			&ret->player_ref->event_handler);
		ret->renderer.direction = ret->player_ref->super.transform.rotation.y;
		ret->renderer.position = vec3f_to_vec2f(ret->player_ref->super.transform.position);
	}
	else
	{
		free_raycasting_scene(ret);
		return (throw_error_str("new_raycasting_scene()",
			"failed to create raycasting scene"));
	}
	return (ret);
}