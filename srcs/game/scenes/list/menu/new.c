/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/08 16:23:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/entities/button_entity.h"
#include "engine/entity_node.h"
#include "engine/error.h"

t_menu_scene	*new_menu_scene(const t_menu_scene_args *const args)
{
	t_menu_scene	*ret;

	if (!(ret = (t_menu_scene*)malloc(sizeof(t_menu_scene))))
		return (NULL);
	if (!init_scene(&ret->super, "Main menu", (void(*)())menu_scene_update,
		(void(*)())menu_scene_render))
	{
		free(ret);
		return (NULL);
	}
	ret->window_size = args->window->size;
	ret->start_game_ref = (t_button_entity*)entity_list_add_entity(
		&ret->super.entities,
		dynamic_button_entity("resources/buttons/start-game-upscale.png",
			"resources/buttons/start-game-hover-upscale.png",
			"resources/buttons/start-game-click-upscale.png",
			args->window));
	ret->close_game_ref = (t_button_entity*)entity_list_add_entity(
		&ret->super.entities,
		dynamic_button_entity("resources/buttons/close-game-upscale.png",
			"resources/buttons/close-game-hover-upscale.png",
			"resources/buttons/close-game-click-upscale.png",
			args->window));
	if (ret->super.module.has_error || ret->super.entities.module.has_error)
	{
		free_menu_scene(ret);
		return (throw_error_str("Failed to create new menu scene"));
	}
	return (ret);
}