/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:05:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/10 12:31:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "containers/list.h"
# include "engine/type.h"
# include "engine/event_handler.h"
# include "engine/entity_list.h"
# include "engine/entity_node.h"

typedef struct	s_scene
{
	t_module		module;
	const char		*const name;
	t_entity_list	entities;
	t_event_handler	input_manager;
	void			(*update_fn)();
	void			(*render_fn)();
}				t_scene;

t_result	init_scene(t_scene *const self,
				const char *const name,
				void (*update_fn)(),
				void (*render_fn)());
void		destroy_scene(t_scene *const self);

#endif
