/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/29 20:21:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/game.h"
#include "game/scenes/raycasting_scene.h"
#include "game/events/events.h"

int	main(void)
{
	t_game	game;

	if (init_game(&game, game_args("wolf3d", ft_usize(1280, 720))) == ERROR)
		return (!throw_error_str("Failed to init game"));
	if (game_set_scene(&game, (t_scene*)new_raycasting_scene(&game.window))
		== ERROR)
	{
		destroy_game(&game);
		return (!throw_error_str("Failed to init menu scene"));
	}
	if (!event_handler_add_callback(&game.event_handler,
		new_close_game_event(NULL)))
	{
		destroy_game(&game);
		return (!throw_error_str("Failed to add exit callback"));
	}
	while (window_is_running(&game.window))
		game_loop(&game);
	destroy_game(&game);
	return (0);
}