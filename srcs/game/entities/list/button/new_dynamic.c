/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dynamic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:59:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 15:50:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/button_entity.h"
#include "engine/error.h"

static void		add_modules(t_button_entity *const self,
					t_button_entity_args *const args)
{
	module_add_stack_module(&self->super.module,
		frame_from_file(args->normal_texture_path), &self->normal_texture);
	module_add_stack_module(&self->super.module,
		frame_from_file(args->hover_texture_path), &self->hover_texture);
	module_add_stack_module(&self->super.module,
		frame_from_file(args->click_texture_path), &self->click_texture);
}

t_button_entity	*new_dynamic_button_entity(t_button_entity_args *const args)
{
	t_button_entity	*ret;

	if (!(ret = (t_button_entity*)malloc(sizeof(t_button_entity))))
	{
		return (throw_error_str("new_dynamic_button_entity()",
			"failed to malloc button entity"));
	}
	if (init_entity_default(&ret->super, button_entity_update) == ERROR)
	{
		free(ret);
		return (throw_error_str("new_dynamic_button_entity()",
			"failed to create button entity"));
	}
	add_modules(ret, args);
	ret->current_texture = &ret->normal_texture;
	ret->is_dynamic = TRUE;
	ret->is_clicked = FALSE;
	ret->window = args->window;
	if (ret->super.module.has_error)
	{
		free_button_entity(ret);
		return (throw_error_str("new_dynamic_button_entity()",
			"failed to create new button entity"));
	}
	return (ret);
}
