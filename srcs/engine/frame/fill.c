/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:29:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/20 21:21:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_fill(t_frame *const self, t_rgba fill_color)
{
	size_t	i;
	size_t	total_size;

	i = 0;
	total_size = self->size.x * self->size.y;
	while (i < total_size)
	{
		((t_rgba*)self->frame)[i] = fill_color;
		i++;
	}
}

// 0xRRGGBBAA