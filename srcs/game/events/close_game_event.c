/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:15:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:12:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/events/events.h"
#include "engine/error.h"

static void		close_game_event(t_game *game, sfEvent *event)
{
	if (event->type == sfEvtClosed ||
		(event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape))
		sfRenderWindow_close(game->window);
}

t_callback_node	*new_close_game_event(void *params)
{
	t_callback_node	*node;

	if (!(node = new_callback_node(close_game_event, params)))
		return (throw_error_str("Failed to create new close game event"));
	return (node);
}