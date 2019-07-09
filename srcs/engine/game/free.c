/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:09:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:03:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/scene.h"
#include "game/scenes/scene_type.h"

void	free_game(t_game *const self)
{
	sfRenderWindow_destroy(self->window);
	free_frame(&self->window_frame);
	free_scene_type(self->scene);
}