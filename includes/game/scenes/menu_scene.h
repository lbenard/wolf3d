/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:48:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_SCENE
# define MENU_SCENE

# include "engine/window.h"
# include "engine/scene.h"
# include "engine/frame.h"
# include "colors/rgb.h"
/*
** Main menu scene
*/
typedef struct	s_menu_scene
{
	t_scene			super;
}				t_menu_scene;

/*
** Constructors
*/
t_menu_scene	*new_menu_scene(const t_window *const window);

/*
** Modifiers
*/
void			menu_scene_update(t_menu_scene *self, float delta);
void			menu_scene_render(t_menu_scene *self, t_frame *fb);

/*
** Destructors
*/
void			free_menu_scene(t_menu_scene *self);

#endif
