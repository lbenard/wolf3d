/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:42:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/01 19:17:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_ENTITY
# define PLAYER_ENTITY

# include "engine/entity.h"
# include "engine/entity_node.h"
# include "engine/scene.h"

typedef struct	s_player_entity
{
	t_entity		super;
	t_event_handler	event_handler;
	float			health;
	size_t			score;
	float			speed;
	t_bool			is_moving;
}				t_player_entity;

t_player_entity	*new_player_entity(void);
void			player_entity_update(t_player_entity *self, t_scene *scene);
void			free_player_entity(t_player_entity *self);

#endif
