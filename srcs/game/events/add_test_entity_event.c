/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_test_entity_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:29:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:39:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/events/events.h"
#include "engine/error.h"
#include "game/entities/test_entity.h"

static void		add_test_entity_event(t_game *game, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace)
	{
		if (!scene_add_entity(game->scene,
			new_entity_node((t_entity*)new_test_entity())))
		{
			throw_error_str("failed to add new test entity");
			window_close(&game->window);
		}
	}
}

t_callback_node	*new_add_test_entity_event(void *params)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(add_test_entity_event, params)))
		return (throw_error_str("Failed to create new add test entity event"));
	return (node);
}