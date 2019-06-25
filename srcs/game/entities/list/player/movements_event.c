/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 19:09:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game/events/events.h"
#include "engine/error.h"
#include "game/entities/player_entity.h"
#include "engine/delta.h"

static void		player_movements_event(t_player_entity *player, sfEvent *event)
{
	(void)player;
	(void)event;
	// if (event->type == sfEvtKeyPressed)
	// {
	// 	if (event->key.code == sfKeyLeft)
	// 		player->super.transform.rotation.y -= 1.0f * get_last_delta();
	// 	if (event->key.code == sfKeyRight)
	// 		player->super.transform.rotation.y += 1.0f * get_last_delta();
	// }
}

t_callback_node	*new_player_movements_event(void *params)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(player_movements_event, params)))
		return (throw_error_str("Failed to create new player movements event"));
	return (node);
}