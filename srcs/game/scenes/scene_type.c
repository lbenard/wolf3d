/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:32:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 16:19:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/scene_type.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"
#include "game/entities/entity_type.h"
#include "engine/entity_node.h"
#include "engine/delta.h"

void	scene_type_update(t_scene *scene, float delta)
{
	if (scene->type == DUMMY_SCENE_TYPE)
		;
	else if (scene->type == MENU_SCENE_TYPE)
		menu_scene_update((t_menu_scene*)scene, delta);
	else if (scene->type == RAYCASTING_SCENE_TYPE)
		raycasting_scene_update((t_raycasting_scene*)scene, delta);
}

void	scene_type_render(t_scene *scene, t_framebuffer *fb)
{
	if (scene->type == DUMMY_SCENE_TYPE)
		;
	else if (scene->type == MENU_SCENE_TYPE)
		menu_scene_render((t_menu_scene*)scene, fb);
	else if (scene->type == RAYCASTING_SCENE_TYPE)
		raycasting_scene_render((t_raycasting_scene*)scene, fb);
}

void	free_scene_type(t_scene *scene)
{
	if (scene->type == DUMMY_SCENE_TYPE)
		;
	else if (scene->type == MENU_SCENE_TYPE)
		free_menu_scene((t_menu_scene*)scene);
	else if (scene->type == RAYCASTING_SCENE_TYPE)
		free_raycasting_scene((t_raycasting_scene*)scene);
}