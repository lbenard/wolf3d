/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:38:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/25 17:41:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_SCENE
# define DUMMY_SCENE

# include "engine/scene.h"

typedef struct	s_dummy_scene
{
	t_scene super;
}				t_dummy_scene;

t_dummy_scene	*new_dummy_scene(void);
t_dummy_scene	*dummy_scene_from_scene(t_scene *scene);
void			free_dummy_scene(t_dummy_scene *self);

#endif
