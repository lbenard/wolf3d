/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:29:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 18:34:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/framebuffer.h"
#include "engine/errors.h"

t_result	init_framebuffer(t_framebuffer *self, t_usize size)
{
	if (!(self->image = sfImage_create(size.x, size.y)))
		return (throw_result_str("failed while creating SFML image"));
	if (!(self->texture = sfTexture_createFromImage(self->image, NULL)))
	{
		sfImage_destroy(self->image);
		return (throw_result_str("failed while creating SFML texture"));
	}
	if (!(self->sprite = sfSprite_create()))
	{
		sfImage_destroy(self->image);
		sfTexture_destroy(self->texture);
		return (throw_result_str("failed while creating SFML sprite"));
	}
	self->size = size;
	self->framebuffer = (t_u32*)sfImage_getPixelsPtr(self->image);
	return (OK);
}

void		framebuffer_update(t_framebuffer *self)
{
	sfTexture_updateFromPixels(self->texture, (sfUint8*)self->framebuffer, self->size.x, self->size.y, 0, 0);
	// sfTexture_updateFromImage(self->texture, self->image, 0, 0);
	sfSprite_setTexture(self->sprite, self->texture, 0);
}

void		framebuffer_clear(t_framebuffer *self)
{
	ft_bzero(self->framebuffer, sizeof(t_u32) * self->size.x * self->size.y);
}

void		free_framebuffer(t_framebuffer *self)
{
	sfImage_destroy(self->image);
	sfTexture_destroy(self->texture);
	sfSprite_destroy(self->sprite);
}
