/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:39:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:12:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "engine/module.h"
# include "engine/window.h"
# include "engine/scene.h"
# include "types.h"
# include "engine/event_handler.h"

/*
** A module that represent the game instance, manages scenes and events
*/
typedef struct				s_game
{
	t_module		module;
	t_window		window;
	t_scene			*scene;
	t_event_handler	event_handler;
}							t_game;

typedef struct				s_game_args
{
	const char	*name;
	t_usize		window_size;
}							t_game_args;

t_game_args					*game_args(const char *const name,
								const t_usize window_size);
t_stack_module_descriptor	game_descriptor(void);

t_game						*game_singleton(void);

t_result					start_game(const t_game_args *const args);

t_result					game_set_scene(t_heap_module_factory factory);
void						game_loop(void);
void						game_close(void);

void						stop_game(void);

#endif
