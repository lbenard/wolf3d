/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:24:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:06:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/scene.h"
#include "game/entities/entity_type.h"

void	destroy_scene(t_scene *const self)
{
	free((void*)self->name);
	list_foreach(&self->entities,
		__builtin_offsetof(t_entity_node, node), free_entity_type);
}