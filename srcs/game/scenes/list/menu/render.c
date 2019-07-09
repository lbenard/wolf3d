/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:03:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/entity_node.h"
#include "game/entities/entity_type.h"
#include "ft/str.h"

void	menu_scene_render(t_menu_scene *self, t_frame *fb)
{
	size_t	x;
	size_t	y;
	t_u32	color;

	color = hsv_to_int(ft_hsv(
		(float)(10 * list_size(&self->test_entity_list) % 360), 1.0f, 1.0f));
	y = 0;
	while (y < fb->size.y)
	{
		x = 0;
		while (x < fb->size.x)
		{
			fb->frame[fb->size.x * y + x] = color;
			x++;
		}
		y++;
	}
}