/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:06:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:35:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_result	game_set_scene(t_game *const self, t_scene *const scene)
{
	if (!scene)
		return (ERROR);
	self->scene = scene;
	window_set_name(&self->window, scene->name);
	event_handler_add_sub_handler(&self->event_handler, &scene->input_manager);
	return (OK);
}