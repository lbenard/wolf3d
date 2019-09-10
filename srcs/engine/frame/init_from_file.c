/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:13:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/08 15:56:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/error.h"
#include "engine/render_texture.h"
#include "engine/sprite.h"
#include "ft/mem.h"

t_result	init_frame_from_file(t_frame *const self, t_frame_args *args)
{
	sfImage		*buffer;
	sfVector2u	frame_size;

	init_module(&self->module);
	if (!(buffer = sfImage_createFromFile(args->path)))
		return (throw_result_str("Cannot load texture path"));
	frame_size = sfImage_getSize(buffer);
	if (frame_size.x == 0 || frame_size.y == 0)
	{
		sfImage_destroy(buffer);
		return (throw_result_str("Cannot create a frame with null horizontal or"
			" vertical size"));
	}
	*(t_usize*)&self->size = ft_usize(frame_size.x, frame_size.y);
	if (!(*(t_u32**)&self->frame =
		(t_u32*)malloc(sizeof(t_u32) * frame_size.x * frame_size.y)))
	{
		sfImage_destroy(buffer);
		return (throw_result_str("Failed while allocating frame"));
	}
	module_add_heap_module(&self->module, render_texture(self->size),
		(void**)&self->render_texture);
	module_add_heap_module(&self->module, sprite(), (void**)&self->sprite);
	if (self->module.has_error == FALSE)
	{
		ft_memcpy(self->frame, sfImage_getPixelsPtr(buffer),
			sizeof(t_u32) * frame_size.x * frame_size.y);
		sfSprite_setTexture(self->sprite,
			sfRenderTexture_getTexture(self->render_texture), 0);
		sfImage_destroy(buffer);
	}
	else
	{
		sfImage_destroy(buffer);
		destroy_frame(self);
		return (throw_result_str("Failed to init frame module"));
	}
	return (OK);
}