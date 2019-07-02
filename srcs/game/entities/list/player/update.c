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
#include <stdio.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"

int		is_safe_move(t_map *map, t_vec3f position, t_vec3f velocity)
{
	float	x_miss;
	float y_miss;

	if (position.x + velocity.x < 0 || position.x + velocity.x >= map->size.x
		|| position.y + velocity.y < 0 || position.y + velocity.y >= map->size.y)
		return (0);
	if (map->map[(int)(position.x + velocity.x) + (int)(position.y + velocity.y) * map->size.x].east_texture_id)
		return (0);
	if ((int)position.x == (int)(position.x + velocity.x)
		|| (int)position.y == (int)(position.y + velocity.y))
		return (1);
	x_miss = velocity.x > 0 ? 1 - (position.x - (int)position.x) : (int)position.x - position.x;
	y_miss = x_miss * velocity.y / velocity.x;
	if ((int)(position.y + y_miss) == (int)position.y)
	{
		if (map->map[(int)(position.x + velocity.x) + (int)position.y * map->size.x].east_texture_id)
			return (0);
		else
			return (1);
	}
	else
	{
		if (map->map[(int)(position.x) + (int)(position.y + velocity.y) * map->size.x].east_texture_id)
			return (0);
		else
		{
			return (1);
		}		
	}
}

void	player_entity_update(t_player_entity *self, t_scene *scene)
{
	t_vec3f	velocity;
	t_raycasting_scene	*raycasting_scene;
	
	velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	raycasting_scene = (t_raycasting_scene*)scene;
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
	if (!is_safe_move(raycasting_scene->renderer.map, self->super.transform.position, velocity))
		return ;
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
