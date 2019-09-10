/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/09 14:38:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"

void	raycasting_scene_render(t_raycasting_scene *self, t_frame *fb)
{
	t_usize		i;
	size_t		size;
	size_t		wall_start;
	float		exceed;
	t_rgba		*texture;
	sfVector2u	texture_size;
	t_rgba		color;

	raycasting_renderer_update(&self->renderer);
	i = ft_usize(0, 0);
	frame_layer(fb, &self->background, ft_isize(0, 0), blend_add);
	texture = (t_rgba*)sfImage_getPixelsPtr(self->texture);
	texture_size = sfImage_getSize(self->texture);
	i = ft_usize(0, 0);
	while (i.x < self->renderer.columns_number)
	{
		exceed = 0.0f;
		size = fb->size.y / self->renderer.columns[i.x].distance;
		if (size > fb->size.y)
			exceed = (size - fb->size.y) * 0.5;
		i.y = 0;
		wall_start = (fb->size.y - size) / 2.0f;
		while (i.y < size && i.y < fb->size.y)
		{
			color.integer = texture[(int)
				(self->renderer.columns[i.x].texture_ratio
				* texture_size.x) + (int)(((i.y + exceed) / size
				* texture_size.y)) * texture_size.x].integer;
			color.c.r /= (self->renderer.columns[i.x].distance / 2.0f) + 1;
			color.c.g /= (self->renderer.columns[i.x].distance / 2.0f) + 1;
			color.c.b /= (self->renderer.columns[i.x].distance / 2.0f) + 1;
			fb->frame[fb->size.x * (wall_start + i.y) + i.x] = color.integer;
			i.y++;
		}
		i.x++;
	}
}