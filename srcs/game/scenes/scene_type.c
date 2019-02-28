/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:32:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 17:38:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/scene_type.h"
#include "game/scenes/menu_scene.h"
#include "game/entities/entity_type.h"
#include "engine/entity_list.h"

void	scene_type_update(t_scene *scene)
{
	t_list_head	*pos;
	t_list_head	*next;

	pos = &scene->entities;
	next = pos->next;
	while ((pos = next) != &scene->entities)
	{
		next = next->next;
		entity_type_update(((t_entity_list*)((t_u8*)pos
			- __builtin_offsetof(t_entity_list, node)))->entity, scene);
	}
}

void	scene_type_render(t_scene *scene)
{
	if (scene->renderer.type == DUMMY_SCENE_TYPE)
		;
	else if (scene->renderer.type == MENU_SCENE_TYPE)
		menu_scene_render(menu_scene_from_scene(scene));
}
