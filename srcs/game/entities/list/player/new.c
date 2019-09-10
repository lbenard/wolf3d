/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:57:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:47:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/player_entity.h"
#include "game/events/events.h"

t_player_entity	*new_player_entity(t_player_entity_args *args)
{
	t_player_entity	*ret;

	if (!(ret = (t_player_entity*)malloc(sizeof(t_player_entity))))
		return (NULL);
	init_entity_default(&ret->super, player_entity_update);
	module_add_stack_module(&ret->super.module, event_handler(ret),
		&ret->event_handler);
	ret->map_ref = args->map;
	ret->speed = 2.0f;
	ret->super.transform.position.x = args->spawn_pos.x;
	ret->super.transform.position.y = args->spawn_pos.y;
	if (ret->super.module.has_error)
	{
		free_player_entity(ret);
		return (NULL);
	}
	return (ret);
}
