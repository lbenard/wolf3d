/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:37:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 04:09:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"
#include "maths/maths.h"

t_bool		is_player_immured(t_vec2d position, t_map *const map)
{
	return (map->map[(int)position.x
		+ (int)position.y * map->size.x].north_texture_ref ||
		map->map[(int)(position.x + 0.1)
		+ (int)position.y * map->size.x].north_texture_ref ||
		map->map[(int)(position.x + 0.1)
		+ (int)(position.y + 0.1) * map->size.x].north_texture_ref ||
		map->map[(int)position.x
		+ (int)position.y * map->size.x].north_texture_ref ||
		map->map[(int)position.x
		+ (int)(position.y + 0.1) * map->size.x].north_texture_ref ||
		map->map[(int)(position.x - 0.1)
		+ (int)(position.y + 0.1) * map->size.x].north_texture_ref ||
		map->map[(int)(position.x - 0.1)
		+ (int)position.y * map->size.x].north_texture_ref ||
		map->map[(int)(position.x - 0.1)
		+ (int)(position.y - 0.1) * map->size.x].north_texture_ref ||
		map->map[(int)position.x
		+ (int)(position.y - 0.1) * map->size.x].north_texture_ref ||
		map->map[(int)(position.x + 0.1)
		+ (int)(position.y - 0.1) * map->size.x].north_texture_ref);
}

t_result	map_parse_player(t_map *const self, char *player_flag_str)
{
	char	**spawn_str;

	spawn_str = wolf_get_values(ft_strstr(player_flag_str, "spawn: "), ' ');
	free(player_flag_str);
	if (!spawn_str || wolf_strsplit_length(spawn_str) != 2)
	{
		wolf_free_values(spawn_str);
		return (throw_result_str("parse_player()", "bad player_spawn data"));
	}
	self->spawn = ft_vec2d(ft_atof(spawn_str[0]), ft_atof(spawn_str[1]));
	if (self->spawn.x < 0.0f || self->spawn.x >= self->size.x ||
		self->spawn.y < 0.0f || self->spawn.y >= self->size.y)
	{
		wolf_free_values(spawn_str);
		return (throw_result_str("parse_player()",
			"player is outside the map"));
	}
	if (is_player_immured(self->spawn, self))
	{
		wolf_free_values(spawn_str);
		return (throw_result_str("parse_player()",
			"player is immured, poor player"));
	}
	wolf_free_values(spawn_str);
	return (OK);
}
