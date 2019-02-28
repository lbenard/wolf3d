/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 15:22:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_SCENE
# define MENU_SCENE

# include "engine/scene.h"

/*
** Main menu scene
*/
typedef struct	s_menu_scene
{
	t_scene	super;
}				t_menu_scene;

/*
** Constructors
*/
t_menu_scene	*new_menu_scene(void);

/*
** Modifiers
*/
void			menu_scene_update(t_menu_scene *self, float delta);
void			menu_scene_render(t_menu_scene *self);

/*
** Casts
*/
t_menu_scene	*menu_scene_from_scene(t_scene *scene);

/*
** Destructors
*/
void			free_menu_scene(t_menu_scene *self);

#endif
