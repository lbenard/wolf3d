/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:20:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

static void	add_modules(t_window *const self, const t_window_args *const args)
{
	module_add_stack_module(&self->module,
		frame(args->size, ft_rgba(0, 0, 0, 255)), &self->frame);
	module_add_stack_module(&self->module,
		cursor_from_file("resources/cursors/cursor-upscale.png"),
		&self->cursor);
}

static void	init_vars(t_window *const self, const t_window_args *const args)
{
	*(t_usize*)&self->size = args->size;
	self->base_name = args->name;
	sfRenderWindow_setVerticalSyncEnabled(self->window, 1);
	sfRenderWindow_setMouseCursorVisible(self->window, 0);
}

t_result	init_window(t_window *const self, const t_window_args *const args)
{
	sfVideoMode	mode;

	init_module(&self->module);
	mode = (sfVideoMode) {.width = args->size.x, .height = args->size.y,
		.bitsPerPixel = 32};
	if (!(self->window = sfRenderWindow_create(mode, args->name, sfClose,
		NULL)))
	{
		return (throw_result_str("init_window()",
			"error while create sfRenderWindow"));
	}
	if (!(self->name = ft_strdup(args->name)))
	{
		sfRenderWindow_destroy(self->window);
		return (throw_result_str("init_window()",
			"error while duplicating window name"));
	}
	add_modules(self, args);
	init_vars(self, args);
	if (self->module.has_error)
	{
		destroy_window(self);
		return (throw_result_str("init_window()", "cannot create window"));
	}
	return (OK);
}
