/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:45:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 02:54:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"
#include "ft/mem.h"

t_result	init_cursor(t_cursor *const self, t_cursor_args *args)
{
	init_module(&self->module);
	module_add_stack_module(&self->module, frame(args->size, args->fill_color),
		&self->cursor);
	self->is_visible = TRUE;
	if (self->module.has_error)
	{
		destroy_cursor(self);
		return (throw_result_str("init_cursor()",
			"failed while creating cursor module"));
	}
	return (OK);
}
