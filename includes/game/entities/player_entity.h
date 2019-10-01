/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:42:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/02 01:03:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ENTITY
# define PLAYER_ENTITY

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
	t_bool			NE;
	t_bool			SE;
	t_bool			SO;
	t_bool			NO;
}						t_corners;

typedef struct			s_player_entity_args
{
	const t_map		*map;
}						t_player_entity_args;

t_heap_module_factory	player_entity(const t_map *const map);

t_player_entity			*new_player_entity(t_player_entity_args *const args);
void					player_entity_update(t_player_entity *const self);
void					free_player_entity(t_player_entity *const self);

#endif
