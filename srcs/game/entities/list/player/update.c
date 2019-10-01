/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/02 01:02:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"
#include "maths/vec2i.h"

t_bool is_position_belong_to_range(t_vec2i pos, t_vec2i min, t_vec2i max)
{
	if (pos.x < min.x || pos.y < min.y || pos.x > max.x || pos.y > max.y)
		return (FALSE);
	else
		return (TRUE);
}

t_bool is_position_belong_to_size(t_vec2i pos, t_usize size)
{
	t_vec2i	min;
	t_vec2i	max;

	min = ft_vec2i(0, 0);
	max = ft_vec2i(size.x - 1, size.y - 1);
	if (!is_position_belong_to_range(pos, min, max))
		return (FALSE);
	else
		return (TRUE);
}

t_bool	is_block_empty(const t_map *const map, t_vec2i pos)
{
	if (!is_position_belong_to_size(pos, map->size))
		return (FALSE);
	else if (map->map[pos.x + pos.y * map->size.x].east_texture_ref)
		return (FALSE);
	else
		return (TRUE);
}

t_corners	corners(t_bool NE, t_bool SE, t_bool SO, t_bool NO)
{
	t_corners corners;

	corners.NE = NE;
	corners.SE = SE;
	corners.SO = SO;
	corners.NO = NO;
	return (corners);
}

t_bool	is_collide(const t_map *const map, t_vec2f move, float box_size, t_corners *box_corner)
{
	if (!is_block_empty(map, ft_vec2i(move.x + box_size, move.y - box_size)))
		box_corner->NE = TRUE;
	if (!is_block_empty(map, ft_vec2i(move.x + box_size, move.y + box_size)))
		box_corner->SE = TRUE;
	if (!is_block_empty(map, ft_vec2i(move.x - box_size, move.y + box_size)))
		box_corner->SO = TRUE;
	if (!is_block_empty(map, ft_vec2i(move.x - box_size, move.y - box_size)))
		box_corner->NO = TRUE;
	if (box_corner->NE || box_corner->SE || box_corner->SO || box_corner->NO)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_vertical_collide(t_corners box)
{
	if (box.NE && box.SE && !box.NO && !box.SO)
		return (TRUE);
	else if (!box.NE && !box.SE && box.NO && box.SO)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_horizontal_collide(t_corners box)
{
	if (box.NE && box.NO && !box.SE && !box.SO)
		return (TRUE);
	else if (!box.NE && !box.NO && box.SE && box.SO)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_corner_collide(t_corners box_corner, float box_size, t_vec3f *vel)
{
	if (box_corner.NE + box_corner.NO + box_corner.SE + box_corner.SO == 1)
	{
		if (box_corner.NE)
			*vel = ft_vec3f(vel->x - box_size, vel->y + box_size, vel->z);
		if (box_corner.SE)
			*vel = ft_vec3f(vel->x - box_size, vel->y - box_size, vel->z);
		if (box_corner.SO)
			*vel = ft_vec3f(vel->x + box_size, vel->y - box_size, vel->z);
		if (box_corner.NO)
			*vel = ft_vec3f(vel->x + box_size, vel->y + box_size, vel->z);
		return (TRUE);
	}
	else
		return (FALSE);
}

t_vec3f		move(const t_map *const map, t_vec3f pos, t_vec3f vel)
{
	float		box_size;
	t_corners	box_corners;
	t_vec2f		next_position;

	box_size = 0.1;
	box_corners = corners(0, 0, 0, 0);
	next_position = ft_vec2f(pos.x + vel.x, pos.y + vel.y);
	if (is_collide(map, next_position, box_size, &box_corners))
	{
		if (is_vertical_collide(box_corners))
			return (ft_vec3f(-vel.x * 0.001, vel.y, vel.z));
		else if (is_horizontal_collide(box_corners))
			return (ft_vec3f(vel.x, -vel.y * 0.001, vel.z));
		else if (is_corner_collide(box_corners, box_size, &vel))
			return (vel);
		else
			return (ft_vec3f(0.0f, 0.0f, 0.0f));
	}
	return (vel);
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
	velocity = move(self->map_ref, self->super.transform.position, velocity);
	self->super.transform.position.x += velocity.x;
	self->super.transform.position.y += velocity.y;
	self->super.transform.position.z += velocity.z;
}
