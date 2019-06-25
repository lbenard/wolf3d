/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 19:11:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"
#include "engine/delta.h"

void	player_entity_update(t_player_entity *self, t_scene *scene)
{
	(void)scene;
	if (sfKeyboard_isKeyPressed(sfKeyW))
		self->super.transform.position.x += 2.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyA))
		self->super.transform.rotation.y -= 2.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyS))
		self->super.transform.position.x -= 2.0f * get_last_delta();
	if (sfKeyboard_isKeyPressed(sfKeyD))
		self->super.transform.rotation.y += 2.0f * get_last_delta();
}
