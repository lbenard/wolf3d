/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/01 19:19:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/entities/player_entity.h"
#include "engine/delta.h"

void	player_entity_update(t_player_entity *self, t_scene *scene)
{
	t_vec3f	velocity;

	(void)scene;
	velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		self->super.transform.rotation.y -= 3.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		self->super.transform.rotation.y += 3.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyW))
	{
		velocity.x += cos(self->super.transform.rotation.y);
		velocity.y += sin(self->super.transform.rotation.y);
	}
	if (sfKeyboard_isKeyPressed(sfKeyA))
	{
		velocity.x += sin(self->super.transform.rotation.y);
		velocity.y -= cos(self->super.transform.rotation.y);
	}
	if (sfKeyboard_isKeyPressed(sfKeyS))
	{
		velocity.x -= cos(self->super.transform.rotation.y);
		velocity.y -= sin(self->super.transform.rotation.y);
	}
	if (sfKeyboard_isKeyPressed(sfKeyD))
	{
		velocity.x -= sin(self->super.transform.rotation.y);
		velocity.y += cos(self->super.transform.rotation.y);
	}
	velocity = vec3f_normalize(velocity);
	velocity = vec3f_scalar(velocity, get_last_delta());
	velocity = vec3f_scalar(velocity, self->speed);
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
