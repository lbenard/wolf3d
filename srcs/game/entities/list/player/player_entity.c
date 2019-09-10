/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:14:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:44:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"

t_heap_module_factory	player_entity(const t_map *const map,
							const t_vec2f spawn_pos)
{
	static t_player_entity_args	args;

	args.map = map;
	args.spawn_pos = spawn_pos;
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(void *(*)())new_player_entity, free_player_entity), &args));
}