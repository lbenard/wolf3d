/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:55:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 19:37:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/error.h"

void	background_framebuffer(t_framebuffer *framebuffer)
{
	(void)framebuffer;
	t_usize	i;
	// t_rgb	sky;
	// t_rgb	floor;
	float	darkness;

	i = ft_usize(0, 0);
	while (i.y < framebuffer->size.y / 2.0f)
	{
		i.x = 0;
		while (i.x < framebuffer->size.x)
		{
			darkness = (((double)framebuffer->size.y / 2.0f) - (double)i.y) / ((double)framebuffer->size.y / 2.0f);
		//	darkness = 1.0f;
			framebuffer->framebuffer[i.y * framebuffer->size.x + i.x] =
				rgb_to_int(ft_rgb(235 * darkness, 206 * darkness, 135 * darkness));
			i.x++;
		}
		i.y++;
	}
	while (i.y < framebuffer->size.y)
	{
		i.x = 0;
		while (i.x < framebuffer->size.x)
		{
			darkness = (((double)framebuffer->size.y / 2.0f) - (double)i.y) / (((double)framebuffer->size.y / 2.0f) - ((double)framebuffer->size.y));
		//	darkness = 1.0f;
			framebuffer->framebuffer[i.y * framebuffer->size.x + i.x] =
				rgb_to_int(ft_rgb(96 * darkness, 128 * darkness, 56 * darkness));
			i.x++;
		}
		i.y++;
	}

}

t_raycasting_scene	*new_raycasting_scene(const t_usize window_size)
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
	if (init_framebuffer(&ret->background, window_size) == ERROR)
	{
		free(ret);
		free_map(&ret->map);
		return (throw_error_str("Failed while initializing framebuffer"));
	}
	ft_bzero(ret->background.framebuffer, sizeof(t_u32) * (window_size.x * window_size.y));
	background_framebuffer(&ret->background);
	if (init_raycasting_renderer(&ret->renderer, window_size, &ret->map) ==
		ERROR)
	{
		free(ret);
		free_map(&ret->map);
		return (throw_error_str("Failed while initializing raycasting "
			"renderer"));
	}
	if (!(ret->texture = sfImage_createFromFile("tnt_wall.png")))
	{
		free(ret);
		free_map(&ret->map);
		free_raycasting_renderer(&ret->renderer);
		return (throw_error_str("Failed while initializing texture"));
	}
	return (ret);
}

#include <stdio.h>
#include <math.h>

void				raycasting_scene_update(t_raycasting_scene *self,
	float delta)
{
	self->renderer.direction += 1.0f * delta;
	if (self->renderer.direction < M_PI)
		self->renderer.direction += 2.0f * M_PI;
	if (self->renderer.direction > M_PI)
		self->renderer.direction -= 2.0f * M_PI;
}

void				raycasting_scene_render(t_raycasting_scene *self,
	t_framebuffer *fb)
{
	t_usize		i;
	// t_u32		bg_color;
	// t_u32		wall_color;
	size_t		size;
	size_t		wall_start;
	t_u32		*texture;
	sfVector2u	texture_size;
	t_rgb		color;

	raycasting_renderer_update(&self->renderer);
	i = ft_usize(0, 0);
	// bg_color = rgb_to_int(ft_rgb(100, 0, 255));
	// wall_color = rgb_to_int(ft_rgb(255, 255, 255));
	// while (i.y < fb->size.y)
	// {
	// 	i.x = 0;
	// 	while (i.x < fb->size.x)
	// 	{
	// 		fb->framebuffer[fb->size.x * i.y + i.x] = bg_color;
	// 		i.x++;
	// 	}
	// 	i.y++;
	// }
	ft_memcpy(fb->framebuffer, self->background.framebuffer, sizeof(t_u32) * (fb->size.x * fb->size.y));
	// printf("x: %lu y: %lu\n", )
	texture = (t_u32*)sfImage_getPixelsPtr(self->texture);
	texture_size = sfImage_getSize(self->texture);
	i = ft_usize(0, 0);
	while (i.x < self->renderer.columns_number)
	{
		size = fb->size.y / self->renderer.columns[i.x].distance;
		if (size > fb->size.y)
			size = fb->size.y;
		i.y = 0;
		wall_start = (fb->size.y - size) / 2.0f;
		while (i.y < size)
		{
			color = ft_rgb_int(texture[(int)(self->renderer.columns[i.x].texture_ratio * texture_size.x)
					+ (int)((((float)i.y / (float)size) * texture_size.y)) * texture_size.x]);
			color.r /= self->renderer.columns[i.x].distance;
			color.g /= self->renderer.columns[i.x].distance;
			color.b /= self->renderer.columns[i.x].distance;
			fb->framebuffer[fb->size.x * (wall_start + i.y) + i.x] = rgb_to_int(color);
			i.y++;
		}
		i.x++;
	}
}

void				free_raycasting_scene(t_raycasting_scene *self)
{
	free_scene(&self->super);
	free_map(&self->map);
	free_raycasting_renderer(&self->renderer);
	free(self);
}