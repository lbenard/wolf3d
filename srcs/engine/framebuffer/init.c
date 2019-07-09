/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:31:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:01:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/error.h"

t_result	init_frame(t_frame *const self, const t_usize size)
{
	if (!(*(t_u32**)&self->frame =
		(t_u32*)malloc(sizeof(t_u32) * size.x * size.y)))
		return (throw_result());
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
	ft_bzero(self->frame, sizeof(t_u32) * (size.x * size.y));
	*(t_usize*)&self->size = size;
	return (OK);
}