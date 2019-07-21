/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:13:32 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/21 16:40:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/blend.h"

void	window_update(t_window *const self)
{
	t_isize	mouse_pos;

	frame_update(&self->frame);
	if (self->cursor.is_visible)
	{
		if (self->cursor.is_custom)
		{
			sfRenderWindow_setMouseCursorVisible(self->window, 0);
			mouse_pos.x = sfMouse_getPositionRenderWindow(self->window).x;
			mouse_pos.y = sfMouse_getPositionRenderWindow(self->window).y;
			frame_layer(&self->frame, &self->cursor.custom_cursor, mouse_pos,
				blend_add);
		}
		else
			sfRenderWindow_setMouseCursorVisible(self->window, 0);
	}
	else
		sfRenderWindow_setMouseCursorVisible(self->window, 0);
	frame_update(&self->frame);
	sfRenderWindow_drawSprite(self->window, self->frame.sprite, NULL);
	sfRenderWindow_display(self->window);
	frame_clear(&self->frame);
}