/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:14:21 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/02 07:22:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/raycasting.h"
#include "engine/error.h"

t_result	init_raycasting(t_raycasting *const self,
				const t_raycasting_args *const args)
{
	init_module(&self->module);
	if (!(*(t_ray**)&self->columns = (t_ray*)malloc(sizeof(t_ray)
		* args->window_size.x)))
	{
		self->module.has_error = TRUE;
		return (throw_result_str("init_raycasting()",
			"error while creating rays array"));
	}
	*(t_map**)&self->map = args->map;
	self->columns_number = args->window_size.x;
	self->direction = 0.0f;
	self->fov = 900.0f;
	return (OK);
}