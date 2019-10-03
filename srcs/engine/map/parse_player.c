/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:37:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 23:59:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"
#include "maths/maths.h"

t_result	map_parse_player(t_map *const self, char *player_flag_str)
{
	char	**spawn_str;

	spawn_str = wolf_get_values(ft_strstr(player_flag_str, "spawn: "), ' ');
	if (!spawn_str || wolf_strsplit_length(spawn_str) != 2)
		return (throw_result_str("parse_player()", "bad player_spawn data"));
	else
		self->spawn = ft_vec2d(ft_atof(spawn_str[0]), ft_atof(spawn_str[1]));
	wolf_free_values(spawn_str);
	free(player_flag_str);
	return (OK);
}
