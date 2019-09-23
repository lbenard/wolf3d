/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/22 18:07:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "engine/frame.h"
#include "engine/blend.h"
#include "ft/mem.h"

void	menu_scene_render(t_menu_scene *self, t_frame *fb)
{
	frame_fill(fb, ft_rgba(33, 55, 71, 255));
	button_entity_render(self->start_game_ref, fb);
	button_entity_render(self->close_game_ref, fb);
	image_entity_render(self->title_ref, fb);
	image_entity_render(self->credits_ref, fb);
	// frame_layer(fb, &self->credits,
	// 	ft_isize(5, fb->size.y - self->credits.size.y - 5), blend_add);
	// frame_layer(fb, &self->title,
	// 	ft_isize(5, fb->size.y - self->credits.size.y - 5), blend_add);
}