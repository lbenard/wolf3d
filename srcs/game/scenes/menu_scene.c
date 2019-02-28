/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 17:33:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/entity_list.h"
#include "game/entities/entity_type.h"
#include "ft/str.h"

#include <stdio.h>

t_menu_scene	*new_menu_scene(void)
{
	t_menu_scene	*ret;

	if (!(ret = (t_menu_scene*)malloc(sizeof(t_menu_scene))))
		return (NULL);
	if (!init_scene(&ret->super, MENU_SCENE_TYPE, "Main menu"))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

#include <stdio.h>

void			menu_scene_update(t_menu_scene *self, float delta)
{
	// printf("Menu scene update\n");
	(void)delta;
	list_foreach(&self->super.entities,
		__builtin_offsetof(t_entity_list, node), entity_type_update);
}


void			menu_scene_render(t_menu_scene *self)
{
	// printf("Menu scene render\n");
	(void)self;
	// list_foreach(&self->super.entities,
	// 	__builtin_offsetof(t_entity_list, node), entity_type_render);
}

t_menu_scene	*menu_scene_from_scene(t_scene *scene)
{
	return ((t_menu_scene*)((t_u8*)scene
		- __builtin_offsetof(t_menu_scene, super)));
}

void			free_menu_scene(t_menu_scene *self)
{
	free_scene(&self->super);
	free(self);
}
