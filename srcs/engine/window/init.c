/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/26 19:17:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	init_window(t_window *const self, const t_window_args *const args)
{
	sfVideoMode	mode;

	init_module(&self->module);
	mode = (sfVideoMode) {.width = args->size.x, .height = args->size.y,
		.bitsPerPixel = 32};
	if (!(self->window = sfRenderWindow_create(mode, args->name, sfClose,
		NULL)))
		return (throw_result_str("init_window()",
			"error while create sfRenderWindow"));
	sfRenderWindow_setMouseCursorVisible(self->window, 0);	
	if (!(self->name = ft_strdup(args->name)))
	{
		sfRenderWindow_destroy(self->window);
		return (throw_result_str("init_window()",
			"error while duplicating window name"));
	}
	module_add_stack_module(&self->module,
		frame(args->size, ft_rgba(0, 0, 0, 255)), &self->frame);
	module_add_stack_module(&self->module,
		cursor_from_file("resources/cursors/cursor-upscale.png"),
		&self->cursor);
	*(t_usize*)&self->size = args->size;
	self->base_name = args->name;
	if (self->module.has_error)
	{
		destroy_window(self);
		return (throw_result_str("init_window()",
			"error while creating window module"));
	}
	return (OK);
}