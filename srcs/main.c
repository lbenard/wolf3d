/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/10 12:08:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/game.h"
#include "engine/lookup_table.h"
#include "game/scenes/menu_scene.h"
#include "game/scenes/raycasting_scene.h"
#include "game/events/events.h"

int	main(void)
{
	t_game	*game;

	game = game_singleton();
	if (start_game(game_args("wolf3d", ft_usize(1200, 600))) == ERROR)
		return (!throw_error_str("Failed to start game"));
	// game_set_scene(menu_scene(&game->window));
	if (!event_handler_add_callback(&game->event_handler,
		new_close_game_event(NULL)))
	{
		stop_game();
		return (!throw_error_str("Failed to add exit callback"));
	}
	if (game->module.has_error)
	{
		stop_game();
		return (!throw_error_str("Failed to init game"));
	}
	while (window_is_running(&game->window))
		game_loop();
	stop_game();
	return (0);
}