/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/21 15:41:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/frame.h"
#include "engine/entity_node.h"
#include "engine/scene.h"
#include "game/entities/test_entity.h"
#include "colors/hsv.h"
#include "engine/game.h"
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/menu_scene.h"
#include "game/events/events.h"
#include "engine/map.h"

// void	rainbow_framebuffer(t_framebuffer *framebuffer)
// {
// 	for (size_t y = 0; y < framebuffer->size.y; y++)
// 		for (size_t x = 0; x < framebuffer->size.x; x++)
// 			framebuffer->framebuffer[framebuffer->size.x * y + x] =
// 				hsv_to_int(ft_hsv((y / (double)framebuffer->size.y * 360.0),
// 					1.0f, 1.0f));
// }

#include <stdio.h>
#include "engine/map.h"
#include "engine/raycasting.h"
#include "engine/blend.h"

int		main(void)
{
	t_game	game;

	if (init_game(&game, "wolf3d", ft_usize(1280, 720)) == ERROR)
		return (!throw_error_str("Failed to init game"));
	if (game_set_scene(&game, (t_scene*)new_raycasting_scene(&game.window))
		== ERROR)
	{
		destroy_game(&game);
		return (!throw_error_str("Failed to init menu scene"));
	}
	// if (game_set_scene(&game, (t_scene*)new_menu_scene(&game.window))
	// 	== ERROR)
	// {
	// 	destroy_game(&game);
	// 	return (!throw_error_str("Failed to init menu scene"));
	// }
	if (!event_handler_add_callback(&game.event_handler,
		new_close_game_event(NULL)))
	{
		destroy_game(&game);
		return (!throw_error_str("Failed to add exit callback"));
	}
	// t_rgba	back = ft_rgba(255, 255, 255, 255);
	// t_rgba	layer = ft_rgba(0, 0, 0, 255);

	// t_rgba	result = ft_rgba_int(blend_add(&back, &layer));
	// printf("result: r: %d, g: %d, b: %d, a: %d\n", result.r, result.g, result.b, result.a);
	while (window_is_running(&game.window))
	{
		game_loop(&game);
		// frame_clear(&game.window.frame);
	}
	destroy_game(&game);
	return (0);
}