/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 18:32:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <SFML/Graphics.h>
# include "engine/framebuffer.h"
# include "engine/scene.h"
# include "types.h"
# include "engine/event_handler.h"

typedef struct	s_game
{
	sfRenderWindow	*const window;
	t_usize			window_size;
	t_framebuffer	window_framebuffer;
	t_scene			*scene;
	t_event_handler	event_handler;
}				t_game;

t_result		init_game(t_game *const self, const char *const name,
	const t_usize window_size);
t_result		game_set_scene(t_game *const self, t_scene *const scene);
void			game_loop(t_game *const self);
t_bool			game_is_running(t_game *const self);
t_bool			game_is_focused(t_game *const self);
void			free_game(t_game *const self);

#endif