/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 06:49:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"

static t_bool	is_colliding(const t_map *const map, t_vec3f pos, t_vec3f vel)
{
	float	x_miss;
	float	y_miss;

	if (pos.x + vel.x < 0 || pos.x + vel.x >= map->size.x
		|| pos.y + vel.y < 0 || pos.y + vel.y >= map->size.y)
		return (FALSE);
	if (map->map[(int)(pos.x + vel.x) + (int)(pos.y + vel.y)
		* map->size.x].east_texture_id)
		return (FALSE);
	if ((int)pos.x == (int)(pos.x + vel.x)
		|| (int)pos.y == (int)(pos.y + vel.y))
		return (TRUE);
	x_miss = vel.x > 0 ? 1 - (pos.x - (int)pos.x) : (int)pos.x - pos.x;
	y_miss = x_miss * vel.y / vel.x;
	if ((int)(pos.y + y_miss) == (int)pos.y)
		return (!(map->map[(int)(pos.x + vel.x)+ (int)pos.y * map->size.x]
			.east_texture_id));
	else
		return (!(map->map[(int)(pos.x) + (int)(pos.y + vel.y) * map->size.x]
			.east_texture_id));
}

static void	orientation(t_vec3f	*rotation)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		rotation->y -= 2.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		rotation->y += 2.0f * get_last_delta();
}

static void	wasd(t_vec3f *transform, t_vec3f rotation)
{
	t_vec2f	rotation_trigonometry;

	rotation_trigonometry = ft_vec2f(cos(rotation.y), sin(rotation.y));
	if (sfKeyboard_isKeyPressed(sfKeyW) && !sfKeyboard_isKeyPressed(sfKeyS))
	{
		transform->x += rotation_trigonometry.x;
		transform->y += rotation_trigonometry.y;
	}
	if (sfKeyboard_isKeyPressed(sfKeyA) && !sfKeyboard_isKeyPressed(sfKeyD))
	{
		transform->x += rotation_trigonometry.y;
		transform->y -= rotation_trigonometry.x;
	}
	if (sfKeyboard_isKeyPressed(sfKeyS) && !sfKeyboard_isKeyPressed(sfKeyW))
	{
		transform->x -= rotation_trigonometry.x;
		transform->y -= rotation_trigonometry.y;
	}
	if (sfKeyboard_isKeyPressed(sfKeyD) && !sfKeyboard_isKeyPressed(sfKeyA))
	{
		transform->x -= rotation_trigonometry.y;
		transform->y += rotation_trigonometry.x;
	}
	*transform = vec3f_normalize(*transform);
}

void	player_entity_update(t_player_entity *self)
{
	t_vec3f	velocity;
	
	velocity = ft_vec3f(0.0f, 0.0f, 0.0f);
	orientation(&self->super.transform.rotation);
	wasd(&velocity, self->super.transform.rotation);
	velocity = vec3f_scalar(velocity, get_last_delta());
	velocity = vec3f_scalar(velocity, self->speed);
	if (sfKeyboard_isKeyPressed(sfKeyLShift))
		velocity = vec3f_scalar(velocity, 2.0f);
	if (!is_colliding(self->map_ref, self->super.transform.position, velocity))
		return ;
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
