/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:32:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:18:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/scene_type.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"

void	free_scene_type(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->type == DUMMY_SCENE_TYPE)
		;
	else if (scene->type == MENU_SCENE_TYPE)
		free_menu_scene((t_menu_scene*)scene);
	else if (scene->type == RAYCASTING_SCENE_TYPE)
		free_raycasting_scene((t_raycasting_scene*)scene);
}