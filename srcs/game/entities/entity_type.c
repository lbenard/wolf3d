/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:52:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 17:41:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/entity_type.h"
#include "game/entities/dummy_entity.h"
#include "game/entities/test_entity.h"

void	entity_type_update(t_entity *entity, t_scene *scene)
{
	if (entity->type == DUMMY_ENTITY_TYPE)
		;
	else if (entity->type == TEST_ENTITY_TYPE)
	{
		test_entity_update(test_entity_from_entity(entity), scene);
	}
}

void	free_entity_type(t_entity *entity)
{
	if (entity->type == DUMMY_ENTITY_TYPE)
		free_dummy_entity(dummy_entity_from_entity(entity));
	else if (entity->type == TEST_ENTITY_TYPE)
		free_test_entity(test_entity_from_entity(entity));
}
