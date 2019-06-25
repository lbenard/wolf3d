/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:45:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:45:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/scene_type.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"

void	scene_type_update(t_scene *scene, float delta)
{
	if (scene->type == DUMMY_SCENE_TYPE)
		;
	else if (scene->type == MENU_SCENE_TYPE)
		menu_scene_update((t_menu_scene*)scene, delta);
	else if (scene->type == RAYCASTING_SCENE_TYPE)
		raycasting_scene_update((t_raycasting_scene*)scene, delta);
}