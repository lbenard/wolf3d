/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:42:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:13:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ENTITY_H
# define PLAYER_ENTITY_H

# include "engine/entity.h"
# include "engine/entity_node.h"
# include "engine/scene.h"
# include "engine/map.h"

typedef struct			s_player_entity
{
	t_entity		super;
	t_event_handler	event_handler;
	const t_map		*map_ref;
	float			speed;
}						t_player_entity;

typedef struct			s_corners
{
	t_bool			ne;
	t_bool			se;
	t_bool			so;
	t_bool			no;
}						t_corners;

t_corners				ft_corners(t_bool ne, t_bool se, t_bool so, t_bool no);

typedef struct			s_player_entity_args
{
	const t_map		*map;
}						t_player_entity_args;

t_heap_module_factory	player_entity(const t_map *const map);

t_player_entity			*new_player_entity(t_player_entity_args *const args);
void					player_entity_update(t_player_entity *const self);
t_bool					is_colliding(const t_map *const map,
							const t_vec2f move,
							const float box_size,
							t_corners *const box_corner);

t_bool					is_vertical_collide(const t_corners box);
t_bool					is_horizontal_collide(const t_corners box);
t_bool					is_corner_collide(const t_corners box_corner,
							t_vec3f *const vel);

t_vec3f					north_east_rebound(const t_vec3f vel);
t_vec3f					south_east_rebound(const t_vec3f vel);
t_vec3f					south_west_rebound(const t_vec3f vel);
t_vec3f					north_west_rebound(const t_vec3f vel);

void					free_player_entity(t_player_entity *const self);

#endif
