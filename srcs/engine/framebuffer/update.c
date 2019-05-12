/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:33:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:43:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/framebuffer.h"

void	framebuffer_update(t_framebuffer *const self)
{
	sfTexture_updateFromPixels((sfTexture*)
		sfRenderTexture_getTexture(self->render_texture),
		(sfUint8*)self->framebuffer, self->size.x, self->size.y, 0, 0);
	sfSprite_setTexture(self->sprite,
		sfRenderTexture_getTexture(self->render_texture), 0);
}