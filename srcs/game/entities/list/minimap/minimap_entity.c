/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:27:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 22:33:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minimap_entity.h"

t_heap_module_factory	minimap_entity(const t_raycasting *renderer,
							const t_usize max_size)
{
	static t_minimap_entity_args	args;

	args.renderer = renderer;
	args.max_size = max_size;
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(t_new_fn)new_minimap_entity, free_minimap_entity), &args));
}
