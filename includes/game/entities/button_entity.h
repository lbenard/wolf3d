/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:47:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:13:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_ENTITY_H
# define BUTTON_ENTITY_H

# include "engine/entity.h"
# include "engine/entity_node.h"
# include "engine/window.h"
# include "engine/scene.h"
# include "engine/frame.h"

/*
** Button entity, represent a clickable button with either only one texture, or
** with classic+hovering+clicked texture (dynamic button constructor).
** The button does not throw any event, `is_clicked` is used to know if the
** button is clicked.
*/
typedef struct			s_button_entity
{
	t_entity		super;
	t_event_handler	event_handler;
	t_bool			is_dynamic;
	t_bool			is_clicked;
	const t_window	*window;
	t_frame			normal_texture;
	t_frame			hover_texture;
	t_frame			click_texture;
	t_frame			*current_texture;
}						t_button_entity;

typedef struct			s_button_entity_args
{
	const char		*normal_texture_path;
	const char		*hover_texture_path;
	const char		*click_texture_path;
	const t_window	*window;
}						t_button_entity_args;

t_heap_module_factory	button_entity(const char *const path,
							const t_window *const window);
t_heap_module_factory	dynamic_button_entity(const char *const normal_path,
							const char *const hover_path,
							const char *const click_path,
							const t_window *const window);

t_button_entity			*new_button_entity(
							const t_button_entity_args *const args);
t_button_entity			*new_dynamic_button_entity(
							const t_button_entity_args *const args);

void					button_entity_update(t_button_entity *const self);
void					button_entity_render(t_button_entity *const self,
							t_frame *const frame);

void					free_button_entity(t_button_entity *const self);

#endif
