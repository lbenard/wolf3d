/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:05:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/06 17:00:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "containers/list.h"
# include "engine/type.h"
# include "engine/event_handler.h"
# include "engine/entity_node.h"

typedef struct	s_scene
{
	const type_t	type;
	const char		*const name;
	t_list_head		entities;
	// t_renderer		renderer;
	t_event_handler	input_manager;
	struct s_scene	*next_scene;
}				t_scene;

t_result	init_scene(t_scene *const self, const type_t type,
	const char *const name);
t_result	scene_add_entity(t_scene *const self, t_entity_node *const node);
void		free_scene(t_scene *const self);

#endif
