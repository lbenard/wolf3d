/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:46:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 17:32:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/scene.h"
#include "ft/str.h"
#include "game/entities/entity_type.h"
#include "engine/entity_list.h"

t_result	init_scene(t_scene *scene, type_t type, const char *name)
{
	if (!(scene->name = ft_strdup(name)))
		return (ERROR);
	scene->type = type;
	if (!init_list_head(&scene->entities))
	{
		free(scene->name);
		return (ERROR);
	}
	scene->next_scene = NULL;
	return (OK);
}

void		free_scene(t_scene *self)
{
	free(self->name);
	list_foreach(&self->entities,
		__builtin_offsetof(t_entity_list, node), free_entity_type);
}
