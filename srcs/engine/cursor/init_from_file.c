/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:36:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:50:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"
#include "ft/mem.h"

t_result	init_cursor_from_file(t_cursor *const self, t_cursor_args *args)
{
	init_module(&self->module);
	module_add_stack_module(&self->module, frame_from_file(args->path),
		&self->cursor);
	self->is_visible = TRUE;
	if (self->module.has_error)
	{
		destroy_cursor(self);
		return (throw_result_str("init_cursor_from_file()",
			"Failed while creating new cursor"));
	}
	return (OK);
}
