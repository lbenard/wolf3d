/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:51:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/10 06:08:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_SCENE
# define RAYCASTING_SCENE

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/raycasting.h"
# include "engine/frame.h"
# include "game/entities/player_entity.h"

typedef struct			s_raycasting_scene
{
	t_scene					super;
	t_map					map;
	t_rgb					ground_color;
	t_rgb					sky_color;
	t_frame					background;
	t_raycasting_renderer	renderer;
	sfImage					*texture;
	t_frame					minimap;
	t_player_entity			*player_ref;
}						t_raycasting_scene;

typedef struct			s_raycasting_scene_args
{
	const t_window	*window;
}						t_raycasting_scene_args;

t_heap_module_factory	raycasting_scene(const t_window *const window);

/*
** Constructors
*/
t_raycasting_scene		*new_raycasting_scene(
							const t_raycasting_scene_args *const args);

/*
** Modifiers
*/
void					raycasting_scene_update(t_raycasting_scene *self);
void					raycasting_scene_render(t_raycasting_scene *self,
							t_frame *fb);

/*
** Destructors
*/
void					free_raycasting_scene(t_raycasting_scene *self);

#endif