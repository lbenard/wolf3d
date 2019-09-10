/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:33:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 18:25:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_update(t_frame *const self)
{
	sfTexture_updateFromPixels((sfTexture*)
		sfRenderTexture_getTexture(self->render_texture),
		(sfUint8*)self->frame, self->size.x, self->size.y, 0, 0);
}