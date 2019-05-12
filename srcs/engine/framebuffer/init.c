/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:31:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 20:20:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/framebuffer.h"
#include "engine/error.h"

t_result	init_framebuffer(t_framebuffer *const self, const t_usize size)
{
	if (!(*(t_u32**)&self->framebuffer =
		(t_u32*)malloc(sizeof(t_u32) * size.x * size.y)))
		return (throw_result());
	if (!(*(sfRenderTexture**)&self->render_texture =
		sfRenderTexture_create(size.x, size.y, 0)))
	{
		free(self->framebuffer);
		return (throw_result_str("failed while creating SFML texture"));
	}
	if (!(*(sfSprite**)&self->sprite = sfSprite_create()))
	{
		free(self->framebuffer);
		sfRenderTexture_destroy(self->render_texture);
		return (throw_result_str("failed while creating SFML sprite"));
	}
	*(t_usize*)&self->size = size;
	return (OK);
}