/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:46:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:04:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/scene_type.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"

void	scene_type_render(t_scene *scene, t_frame *fb)
{
	if (scene->type == DUMMY_SCENE_TYPE)
		;
	else if (scene->type == MENU_SCENE_TYPE)
		menu_scene_render((t_menu_scene*)scene, fb);
	else if (scene->type == RAYCASTING_SCENE_TYPE)
		raycasting_scene_render((t_raycasting_scene*)scene, fb);
}