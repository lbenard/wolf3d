/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:32:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 16:20:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/minimap_entity.h"
#include "engine/error.h"

t_minimap_entity	*new_minimap_entity(const t_minimap_entity_args *const args)
{
	t_minimap_entity	*ret;
	t_usize				map_size;
	float				x_ratio;
	float				y_ratio;

	if (!(ret = (t_minimap_entity*)malloc(sizeof(t_minimap_entity))))
		return (throw_error_str("new_minimap_entity()",
			"failed while allocating new minimap entity"));
	init_entity_default(&ret->super, minimap_entity_update);
	map_size = args->renderer->map->size;
	x_ratio = (float)map_size.x / args->max_size.x;
	y_ratio = (float)map_size.y / args->max_size.y;
	if (x_ratio > y_ratio)
		ret->size = ft_usize(map_size.x / x_ratio, map_size.y / x_ratio);
	else
		ret->size = ft_usize(map_size.x / y_ratio, map_size.y / y_ratio);
	module_add_stack_module(&ret->super.module,
		frame(ret->size, ft_rgba(255, 255, 255, 64)), &ret->minimap);
	ret->raycasting_ref = args->renderer;
	if (ret->super.module.has_error)
		return (throw_error_str("new_minimap_entity()",
			"failed while creating minimap entity"));
	return (ret);
}
