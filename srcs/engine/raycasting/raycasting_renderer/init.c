/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:14:21 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 18:29:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/raycasting.h"
#include "engine/error.h"

t_result	init_raycasting_renderer(t_raycasting_renderer *const self,
	const t_usize window_size, t_map *const map)
{
	if (!(*(t_ray**)&self->columns = (t_ray*)malloc(sizeof(t_ray)
		* window_size.x)))
		return (throw_result_str("Error while creating rays array"));
	*(t_map**)&self->map = map;
	self->columns_number = window_size.x;
	self->position = map->spawn_position;
	self->direction = 0.0f;
	self->fov = 70.0f;
	init_list_head(&self->sprites);
	return (OK);
}