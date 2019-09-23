/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:14:21 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/23 19:13:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/raycasting.h"
#include "engine/error.h"

t_result	init_raycasting_renderer(t_raycasting_renderer *const self,
				const t_raycasting_renderer_args *const args)
{
	init_module(&self->module);
	if (!(*(t_ray**)&self->columns = (t_ray*)malloc(sizeof(t_ray)
		* args->window_size.x)))
	{
		self->module.has_error = TRUE;
		return (throw_result_str("Error while creating rays array"));
	}
	*(t_map**)&self->map = args->map;
	self->columns_number = args->window_size.x;
	// self->position = args->map->spawn_position;
	self->direction = 0.0f;
	self->fov = 900.0f;
	return (OK);
}