/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:05:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 15:29:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "containers/list.h"
# include "engine/type.h"
# include "engine/renderer.h"

typedef struct	s_scene
{
	type_t			type;
	char			*name;
	t_list_head		entities;
	t_renderer		renderer;
	// t_input_manager	input_manager;
	struct s_scene	*next_scene;
}				t_scene;

t_result	init_scene(t_scene *scene, type_t type, const char *name);
void		free_scene(t_scene *self);

#endif
