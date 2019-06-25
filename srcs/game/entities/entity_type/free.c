/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:05:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:06:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/entity_type.h"
#include "game/entities/dummy_entity.h"
#include "game/entities/test_entity.h"

void	free_entity_type(t_entity_node *node)
{
	t_entity	*entity;

	entity = node->entity;
	if (entity->type == DUMMY_ENTITY_TYPE)
		free_dummy_entity((t_dummy_entity*)entity);
	else if (entity->type == TEST_ENTITY_TYPE)
		free_test_entity((t_test_entity*)entity);
}