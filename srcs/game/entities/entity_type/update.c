/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:04:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 19:07:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/entity_type.h"
#include "game/entities/dummy_entity.h"
#include "game/entities/test_entity.h"
#include "game/entities/player_entity.h"

void	entity_type_update(t_entity_node *node, t_scene *scene)
{
	t_entity	*entity;
	
	entity = node->entity;
	if (entity->type == DUMMY_ENTITY_TYPE)
		;
	else if (entity->type == TEST_ENTITY_TYPE)
		test_entity_update((t_test_entity*)entity, scene);
	else if (entity->type == PLAYER_ENTITY_TYPE)
		player_entity_update((t_player_entity*)entity, scene);
}