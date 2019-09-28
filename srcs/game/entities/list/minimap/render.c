/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:06:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 17:31:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minimap_entity.h"
#include "maths/vec2i.h"

#include <stdio.h>

// static void	update_bresenham(ssize_t *err, t_isize *a, t_isize d, t_isize s)
// {
// 	ssize_t	e;

// 	e = *err;
// 	if (e > -d.x)
// 	{
// 		*err -= d.y;
// 		a->x += s.x;
// 	}
// 	if (e < d.y)
// 	{
// 		*err += d.x;
// 		a->y += s.y;
// 	}
// }

// static int	ft_abs(int a)
// {
// 	return ((a < 0) ? -a : a);
// }

// static void	draw_line(t_frame *const frame,
// 				t_isize a,
// 				t_isize b,
// 				const t_rgba color)
// {
// 	t_isize	d;
// 	t_isize	s;
// 	float	step;
// 	ssize_t	err;

// 	d = ft_isize(ft_abs(b.x - a.x), ft_abs(b.y - a.y));
// 	s = ft_isize(a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1);
// 	step = (d.x > d.y) ? d.x : d.y;
// 	err = (d.x > d.y ? d.x : -d.y) / 2;
// 	while (step--)
// 	{
// 		frame->frame[(a.y * frame->size.x) + a.x] = color.integer;
// 		update_bresenham(&err, &a, d, s);
// 	}
// }

void		minimap_entity_render(t_minimap_entity *const self,
				t_frame *const frame)
{
	t_vec2f	pos;
	t_usize	frame_player_pos;
	size_t	i;

	// frame_fill(&self->minimap, ft_rgba(255, 255, 255, 64));
	pos = self->raycasting_ref->position;
	printf("pos: x: %f, y: %f\n", pos.x, pos.y);
	frame_player_pos = ft_usize(pos.x / self->raycasting_ref->map->size.x * self->minimap.size.x,
		pos.y / self->raycasting_ref->map->size.y * self->minimap.size.y);
	// if (i == self->raycasting_ref->columns_number)
	// 	i = 0;
	while (i < self->raycasting_ref->columns_number)
	{
		t_usize	frame_ray_pos;

		frame_ray_pos = ft_usize(self->raycasting_ref->columns[i].hit_position.x
			/ self->raycasting_ref->map->size.x * self->minimap.size.x,
			self->raycasting_ref->columns[i].hit_position.y
			/ self->raycasting_ref->map->size.y * self->minimap.size.y);
		self->minimap.frame[frame_ray_pos.y * self->minimap.size.x + frame_ray_pos.x]
			= ft_rgba(255, 0, 0, 255).integer;
		// draw_line(&self->minimap, ft_isize(frame_player_pos.x, frame_player_pos.y),
			// ft_isize(frame_ray_pos.x, frame_ray_pos.y), ft_rgba(255, 0, 0, 255));
		i++;
		// break;
	}
	frame_layer(frame, &self->minimap, ft_isize(0, 0), blend_add);
	frame->frame[frame_player_pos.y * frame->size.x + frame_player_pos.x] = ft_rgba(255, 255, 255, 255).integer;
	// draw_line(frame, ft_isize(0, 0), ft_isize(100, 100), ft_rgba(255, 0, 0, 255));
	// frame->frame[(float)self->size.x * (pos.y / self->size.y * self->minimap.size.y)
	// 	+ (pos.x / self->size.x * self->minimap.size.y)]
	// 	= ft_rgba(255, 255, 255, 255).integer;
}