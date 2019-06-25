/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:57:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 17:42:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/player_entity.h"
#include "game/entities/entity_type.h"
#include "game/events/events.h"

t_player_entity	*new_player_entity(void)
{
	t_player_entity	*ret;

	if (!(ret = (t_player_entity*)malloc(sizeof(t_player_entity))))
		return (NULL);
	init_entity_default(&ret->super, PLAYER_ENTITY_TYPE);
	if (init_event_handler(&ret->event_handler, ret) == ERROR)
	{
		free(ret);
		return (NULL);
	}
	ret->health = 100.0f;
	ret->score = 0;
	ret->is_moving = 0;
	if (event_handler_add_callback(&ret->event_handler,
		new_player_movements_event(NULL)) == ERROR)
	{
		free_event_handler(&ret->event_handler);
		free(ret);
		return (NULL);
	}
	return (ret);
}
