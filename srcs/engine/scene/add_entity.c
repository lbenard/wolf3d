/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:23:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 20:23:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/scene.h"

t_result	scene_add_entity(t_scene *const self, t_entity_node *const node)
{
	if (!node->entity)
		return (ERROR);
	list_add_entry(&node->node, &self->entities);
	return (OK);
}