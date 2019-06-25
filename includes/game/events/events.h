/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:15:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 17:41:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "engine/game.h"
# include <SFML/Window.h>

t_callback_node	*new_close_game_event(void *params);
t_callback_node	*new_add_test_entity_event(void *params);
t_callback_node	*new_player_movements_event(void *params);

#endif