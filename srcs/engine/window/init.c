/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:40:27 by lbenard          ###   ########.fr       */
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
		return (throw_result_str("Error while create sfRenderWindow"));
	sfRenderWindow_setMouseCursorVisible(self->window, 0);	
	if (!(self->name = ft_strdup(args->name)))
	{
		sfRenderWindow_destroy(self->window);
		return (throw_result_str("Error while duplicating window name"));
	}
	module_add_stack_module(&self->module,
		frame(args->size, ft_rgba(0, 0, 0, 255)), &self->frame);
	module_add_stack_module(&self->module,
		cursor(ft_usize(32, 32), ft_rgba(255, 255, 255, 127)), &self->cursor);
	*(t_usize*)&self->size = args->size;
	if (self->module.has_error)
	{
		destroy_window(self);
		return (throw_result_str("Error while creating window module"));
	}
	return (OK);
}