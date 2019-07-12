/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:31:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/11 23:30:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/error.h"

t_result	init_frame(t_frame *const self, const t_usize size,
	t_rgba fill_color)
{
	if (size.x == 0 || size.y == 0)
		return (throw_result_str("Cannot create a frame with null horizontal or"
			" vertical size"));
	if (!(*(t_u32**)&self->frame =
		(t_u32*)malloc(sizeof(t_u32) * size.x * size.y)))
		return (throw_result_str("Failed while allocating frame"));
	if (!(*(sfRenderTexture**)&self->render_texture =
		sfRenderTexture_create(size.x, size.y, 0)))
	{
		free(self->frame);
		return (throw_result_str("failed while creating SFML texture"));
	}
	if (!(*(sfSprite**)&self->sprite = sfSprite_create()))
	{
		free(self->frame);
		sfRenderTexture_destroy(self->render_texture);
		return (throw_result_str("failed while creating SFML sprite"));
	}
	*(t_usize*)&self->size = size;
	frame_fill(self, fill_color);
	return (OK);
}