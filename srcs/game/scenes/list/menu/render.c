/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/10 06:12:21 by lbenard          ###   ########.fr       */
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
	frame_layer(fb,
		self->start_game_ref->current_texture,
		ft_isize(
			self->start_game_ref->super.transform.position.x,
			self->start_game_ref->super.transform.position.y),
		blend_add);
	frame_layer(fb,
		self->close_game_ref->current_texture,
		ft_isize(
			self->close_game_ref->super.transform.position.x,
			self->close_game_ref->super.transform.position.y),
		blend_add);
}