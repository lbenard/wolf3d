/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:52:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 15:51:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/entity_type.h"
#include "game/entities/dummy_entity.h"
#include "game/entities/test_entity.h"

void			entity_type_update(t_entity_node *node, t_scene *scene)
{
	t_entity	*entity;
	
	entity = node->entity;
	if (entity->type == DUMMY_ENTITY_TYPE)
		;
	else if (entity->type == TEST_ENTITY_TYPE)
		test_entity_update((t_test_entity*)entity, scene);
}

void			free_entity_type(t_entity_node *node)
{
	t_entity	*entity;

	entity = node->entity;
	if (entity->type == DUMMY_ENTITY_TYPE)
		free_dummy_entity((t_dummy_entity*)entity);
	else if (entity->type == TEST_ENTITY_TYPE)
		free_test_entity((t_test_entity*)entity);
}

static t_bool	list_has_entity_ptr(const t_list_head *const list,
	const t_entity_node *const entity)
{
	const t_list_head	*pos;
	const t_list_head	*next;
	const t_entity_node	*node;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		node = (t_entity_node*)pos;
		if (node->entity == entity->entity)
			return (1);
	}
	return (0);
}

t_result		get_entities_from_type(t_list_head *const dest,
	const t_list_head *const from, const type_t type)
{
	const t_list_head	*pos;
	const t_list_head	*next;
	const t_entity_node	*node;
	t_entity_node		*new_entry;

	pos = from;
	next = pos->next;
	while ((pos = next) != from)
	{
		next = next->next;
		node = (t_entity_node*)pos;
		if (node->entity->type == type && !list_has_entity_ptr(dest, node))
		{
			if (!(new_entry = new_entity_node(node->entity)))
				return (ERROR);
			list_add_entry(&new_entry->node, dest);
		}
	}
	return (OK);
}
