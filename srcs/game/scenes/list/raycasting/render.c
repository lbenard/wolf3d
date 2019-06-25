/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 17:44:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/mem.h"

void	raycasting_scene_render(t_raycasting_scene *self, t_framebuffer *fb)
{
	t_usize		i;
	size_t		size;
	size_t		wall_start;
	t_u32		*texture;
	sfVector2u	texture_size;
	t_rgb		color;

	raycasting_renderer_update(&self->renderer);
	i = ft_usize(0, 0);
	ft_memcpy(fb->framebuffer, self->background.framebuffer,
		sizeof(t_u32) * (fb->size.x * fb->size.y));
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
			color = ft_rgb_int(
				texture[(int)(self->renderer.columns[i.x].texture_ratio
					* texture_size.x) + (int)((((float)i.y / (float)size)
					* texture_size.y)) * texture_size.x]);
			color.r /= self->renderer.columns[i.x].distance;
			color.g /= self->renderer.columns[i.x].distance;
			color.b /= self->renderer.columns[i.x].distance;
			fb->framebuffer[fb->size.x * (wall_start + i.y) + i.x]
				= rgb_to_int(color);
			i.y++;
		}
		i.x++;
	}
}