/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:22:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:41:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/scene.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	init_scene(t_scene *const self,
				const char *const name,
				void (*update_fn)(),
				void (*render_fn)())
{
	init_module(&self->module);
	if (!(*(char**)&self->name = ft_strdup(name)))
	{
		self->module.has_error = TRUE;
		return (ERROR);
	}
	module_add_stack_module(&self->module, entity_list(), &self->entities);
	module_add_stack_module(&self->module, event_handler(self),
		&self->input_manager);
	self->update_fn = update_fn;
	self->render_fn = render_fn;
	if (self->module.has_error)
	{
		destroy_scene(self);
		return (throw_result_str("Failed while creating new scene"));
	}
	return (OK);
}
