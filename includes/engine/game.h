/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:24:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "engine/window.h"
# include "engine/scene.h"
# include "types.h"
# include "engine/event_handler.h"

typedef struct	s_game
{
	t_window		window;
	t_scene			*scene;
	t_event_handler	event_handler;
}				t_game;

t_result		init_game(t_game *const self, const char *const name,
	const t_usize window_size);
t_result		game_set_scene(t_game *const self, t_scene *const scene);
void			game_loop(t_game *const self);
void			destroy_game(t_game *const self);

#endif