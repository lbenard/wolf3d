/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:51:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:11:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycasting.h"

void	raycasting_renderer_update(const t_raycasting_renderer *const self)
{
	size_t	column;
	float	angle;
	float	fisheye_correction;
	t_angle	direction;

	column = 0;
	while (column < self->columns_number)
	{
		angle = atan((float)(column - (self->columns_number * 0.5))
			/ (float)(self->columns_number * 0.5));
		direction = ft_angle(self->direction + angle);
		fisheye_correction = angle;
		self->columns[column] = find_obstacle(self, cos(fisheye_correction),
			direction);
		column++;
	}
}
