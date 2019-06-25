/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:45:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/11 18:39:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine/map.h"
#include "ft/str.h"
#include "maths/maths.h"
#include "engine/error.h"

static t_result	fill_map_size(t_usize *size, int map_fd)
{
	char	*str;

	if (ft_get_next_line(map_fd, &str) == LINE_READ)
	{
		if (!ft_isnumber(str))
			return (throw_result_str("Failed while getting map width"));
		size->x = (size_t)ft_atoi(str);
		free(str);
	}
	else
		return (throw_result_str("GNL failed while parsing map size"));
	if (ft_get_next_line(map_fd, &str) == LINE_READ)
	{
		if (!ft_isnumber(str))
			return (throw_result_str("Failed while getting map height"));
		size->y = (size_t)ft_atoi(str);
		free(str);
	}
	else
		return (throw_result_str("GNL failed while parsing map size"));
	return (OK);
}

static t_result	fill_map_line(t_map *map, size_t line, int map_fd)
{
	size_t	x;
	char	*str;

	x = 0;
	if (ft_get_next_line(map_fd, &str) != LINE_READ)
		return (throw_result_str("GNL failed while parsing map"));
	while (*str && x < map->size.x && (str = (char*)ft_skipchr(str, ' ')))
	{
		if (!ft_isnumber(str))
			return (throw_result_str("Failed while parsing map: "
				"not a number"));
		map->map[x + map->size.x * line].north_texture_id = ft_atoi(str);
		map->map[x + map->size.x * line].east_texture_id = ft_atoi(str);
		map->map[x + map->size.x * line].south_texture_id = ft_atoi(str);
		map->map[x + map->size.x * line].west_texture_id = ft_atoi(str);
		x++;
		if (!(str = ft_strchr(str, ' ')))
			break ;
	}
	if (x != map->size.x || str != NULL)
		return (throw_result_str("Failed while parsing map: "
			"incorrect width"));
	return (OK);
}

static t_result	fill_map_data(t_map *map, int map_fd)
{
	size_t	y;
	char	*str;

	y = 0;
	while (y < map->size.y)
	{
		if (fill_map_line(map, y, map_fd) == ERROR)
			return (throw_result_str("Error while parsing map line"));		
		y++;
	}
	if (ft_get_next_line(map_fd, &str) != READ_FINISH)
	{
		free(str);
		return (throw_result_str("Failed while parsing map: "
			"file is too big"));
	}
	return (OK);
}

t_result		init_map(t_map *self, const char *const path)
{
	int	map_fd;

	if ((map_fd = open(path, O_RDONLY)) < 0)
		return (throw_result_str("Failed while opening map path"));
	if (fill_map_size(&self->size, map_fd) == ERROR)
	{
		close(map_fd);
		return (throw_result_str("Failed while parsing map size"));
	}
	if (!(self->map = (t_wall*)malloc(sizeof(t_wall)
		* (self->size.x * self->size.y))))
	{
		close(map_fd);
		return (throw_result_str("Failed while malloc'ing map content"));
	}
	if (fill_map_data(self, map_fd) == ERROR)
	{
		close(map_fd);
		free(self->map);
		return (throw_result_str("Failed while filling map content"));
	}
	self->spawn_position.x = self->size.x / 2;
	self->spawn_position.y = self->size.y / 2;
	close(map_fd);
	return (OK);
}
