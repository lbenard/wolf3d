/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:06:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/07 17:17:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_result	game_set_scene(t_game *const self, t_scene *const scene)
{
	if (!scene)
		return (ERROR);
	self->scene = scene;
	sfRenderWindow_setTitle(self->window, scene->name);
	self->event_handler.sub_handler = &self->scene->input_manager;
	return (OK);
}