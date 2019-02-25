/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:29:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/25 17:16:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/framebuffer.h"
#include "engine/errors.h"

t_result	init_framebuffer(t_framebuffer *self, t_usize size)
{
	if (!(self->framebuffer = (t_u32*)malloc(sizeof(t_u32) * size.x * size.y)))
		return (throw_result());
	if (!(self->texture = sfTexture_create(size.x, size.y)))
	{
		free(self->framebuffer);
		return (throw_result_str("failed while creating SFML texture"));
	}
	if (!(self->sprite = sfSprite_create()))
	{
		free(self->framebuffer);
		sfTexture_destroy(self->texture);
		return (throw_result_str("failed while creating SFML sprite"));
	}
	self->size = size;
	return (OK);
}

void		framebuffer_update(t_framebuffer *self)
{
	sfTexture_updateFromPixels(self->texture, (sfUint8*)self->framebuffer,
		self->size.x, self->size.y, 0, 0);
	sfSprite_setTexture(self->sprite, self->texture, 0);
}

void		framebuffer_clear(t_framebuffer *self)
{
	ft_bzero(self->framebuffer, sizeof(t_u32) * self->size.x * self->size.y);
}

void		framebuffer_display(t_framebuffer *self, sfRenderWindow *target)
{
	sfRenderWindow_drawSprite(target, self->sprite, NULL);
	sfRenderWindow_display(target);
}

void		free_framebuffer(t_framebuffer *self)
{
	free(self->framebuffer);
	sfTexture_destroy(self->texture);
	sfSprite_destroy(self->sprite);
}
