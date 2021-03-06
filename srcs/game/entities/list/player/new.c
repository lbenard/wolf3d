/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:57:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:13:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/error.h"
#include "game/entities/player_entity.h"
#include "game/events/events.h"

t_player_entity	*new_player_entity(const t_player_entity_args *const args)
{
	t_player_entity	*ret;

	if (!(ret = (t_player_entity*)malloc(sizeof(t_player_entity))))
		return (NULL);
	init_entity_default(&ret->super, player_entity_update);
	module_add_stack_module(&ret->super.module, event_handler(ret),
		&ret->event_handler);
	ret->map_ref = args->map;
	ret->speed = 2.0f;
	ret->super.transform.position.x = args->map->spawn.x;
	ret->super.transform.position.y = args->map->spawn.y;
	if (ret->super.module.has_error)
	{
		free_player_entity(ret);
		return (throw_error_str("new_player_entity()",
			"failed while creating new player entity"));
	}
	return (ret);
}
