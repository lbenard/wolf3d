/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:22:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 18:11:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/scene.h"
#include "ft/str.h"

t_result	init_scene(t_scene *const self, const type_t type,
	const char *const name)
{
	if (!(*(char**)&self->name = ft_strdup(name)))
		return (ERROR);
	*(type_t*)&self->type = type;
	if (!init_list_head(&self->entities))
	{
		free((void*)self->name);
		return (ERROR);
	}
	if (init_event_handler(&self->input_manager, self) == ERROR)
	{
		free((void*)self->name);
		return (ERROR);
	}
	self->next_scene = NULL;
	return (OK);
}
