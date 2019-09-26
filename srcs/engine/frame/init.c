/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:31:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/26 19:08:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/sprite.h"
#include "engine/render_texture.h"
#include "engine/error.h"

t_result	init_frame(t_frame *const self, t_frame_args *args)
{
	init_module(&self->module);
	if (args->size.x == 0 || args->size.y == 0)
		return (throw_result_str("init_frame()",
			"cannot create a frame with null horizontal or vertical size"));
	if (!(*(t_u32**)&self->frame =
		(t_u32*)malloc(sizeof(t_u32) * args->size.x * args->size.y)))
		return (throw_result_str("init_frame()",
			"failed while allocating frame"));
	module_add_heap_module(&self->module,
		render_texture(args->size), (void**)&self->render_texture);
	module_add_heap_module(&self->module, sprite(), (void**)&self->sprite);
	*(t_usize*)&self->size = args->size;
	frame_fill(self, args->fill_color);
	if (self->module.has_error == FALSE)
		sfSprite_setTexture(self->sprite,
			sfRenderTexture_getTexture(self->render_texture), 0);
	else
	{
		destroy_frame(self);
		return (throw_result_str("init_frame()",
			"failed to init frame module"));
	}
	return (OK);
}