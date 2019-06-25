/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:18:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"
#include "game/entities/entity_type.h"

void	menu_scene_update(t_menu_scene *self, float delta)
{
	(void)delta;
	// get_entities_from_type(&self->test_entity_list,
	// 	&self->super.entities,
	// 	TEST_ENTITY_TYPE);
	list_foreach(&self->test_entity_list, 0, entity_type_update);
}