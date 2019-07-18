/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:49:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"
#include "game/entities/entity_type.h"

void	menu_scene_update(t_menu_scene *self, float delta)
{
	const t_list_head	*pos;

	(void)delta;
	pos = &self->super.entities;
	while ((pos = pos->next) != &self->super.entities)
		entity_type_update((t_entity_node*)pos, &self->super);
}