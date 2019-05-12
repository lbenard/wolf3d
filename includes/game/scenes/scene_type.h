/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:35:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 15:56:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_TYPE
# define SCENE_TYPE

# include "engine/scene.h"
# include "engine/framebuffer.h"

typedef enum	s_scene_type
{
	DUMMY_SCENE_TYPE,
	MENU_SCENE_TYPE,
	RAYCASTING_SCENE_TYPE
}				t_scene_type;

void			scene_type_update(t_scene *scene, float delta);
void			scene_type_render(t_scene *scene, t_framebuffer *fb);
void			free_scene_type(t_scene *scene);

#endif
