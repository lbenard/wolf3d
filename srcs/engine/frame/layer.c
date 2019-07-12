/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:39:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/10 00:49:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_layer(t_frame *self, t_frame *layer, t_isize pos,
			void (*blend)(t_rgba *const a, const t_rgba *const b))
{
	t_usize	start;
	t_usize	size;
	t_usize	i;

	if (pos.x >= (ssize_t)self->size.x || pos.y >= (ssize_t)self->size.y
		|| pos.x + (ssize_t)layer->size.x <= 0
		|| pos.y + (ssize_t)layer->size.y <= 0)
		return ;
	start = ft_usize((pos.x < 0) ? -pos.x : 0, (pos.y < 0) ? -pos.y : 0);
	size.x = ft_min(pos.x + layer->size.x, self->size.x) - ft_max(pos.x, 0);
	size.y = ft_min(pos.y + layer->size.y, self->size.y) - ft_max(pos.y, 0);
	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			blend((t_rgba*)(self->frame + self->size.x * (pos.y + start.y + i.y)
				+ (pos.x + start.x + i.x)),
				(t_rgba*)(layer->frame + layer->size.x * (start.y + i.y)
				+ (start.x + i.x)));
			i.x++;
		}
		i.y++;
	}
}