/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 19:12:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/entity_type.h"

void	raycasting_scene_update(t_raycasting_scene *self, float delta)
{
	const t_list_head	*pos;

	(void)delta;
	pos = &self->super.entities;
	while ((pos = pos->next) != &self->super.entities)
		entity_type_update((t_entity_node*)pos, &self->super);
	self->renderer.direction = self->player_ref->super.transform.rotation.y;
	self->renderer.position = vec3f_to_vec2f(self->player_ref->super.transform.position);
	if (self->renderer.direction < M_PI)
		self->renderer.direction += 2.0f * M_PI;
	if (self->renderer.direction > M_PI)
		self->renderer.direction -= 2.0f * M_PI;
	// self->renderer.position.y += 1.0f * delta;
	// if (self->renderer.position.y > 1.0f)
	// 	self->renderer.position.y = -1.0f;
	// printf("y: %f", self->renderer.position.y);
}