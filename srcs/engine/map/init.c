/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:45:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/23 18:39:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine/map.h"
#include "ft/str.h"
#include "maths/maths.h"
#include "engine/error.h"

#include <stdio.h>
/*
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

t_result		init_map(t_map *self, const t_map_args *const args)
{
	int	map_fd;

	init_module(&self->module);
	if ((map_fd = open(args->path, O_RDONLY)) < 0)
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
	self->spawn_position = ft_vec2f(self->size.x / 2, self->size.y / 2);
	close(map_fd);
	return (OK);
}
*/


////////////////////////////////////////////////////// TEST

void	list_print_texture(t_texture_node *texture)
{
	printf("%s\n", texture->name);
}
void	list_print_bloc(t_bloc_node *bloc)
{
	printf("%s: ", bloc->key);
	printf("%s ", bloc->north_texture_name);
	printf("%s ", bloc->east_texture_name);
	printf("%s ", bloc->south_texture_name);
	printf("%s\n", bloc->west_texture_name);
}



////////////////////////////////////////////////////// WOLF GET DATA

t_result	is_wolf_flag_safe(char *line)
{
	if (!line || !(*line))
		return (ERROR);
	line++;
	while (*line)
	{
		if (!ft_isalnum(*line) && *line != '_')
			return (ERROR);
		line++;
	}
	return (OK);
}

t_result	is_wolf_data_line_safe(char *line, char end)
{
	while (line && *line && *line != ':' && *line != end)
	{
		if (!ft_isalnum(*line) && *line != '_')
			return (ERROR);
		line++;
	}
	if (!line || *line != ':' || line[1] != ' ')
		return (ERROR);
	else
		return (OK);
}

t_result	is_syntax_safe(char *line)
{
	if (line && *line == '\0')
		return (OK);
	else if (line && *line == '-' && is_wolf_flag_safe(line))
		return (OK);
	else if (line && is_wolf_data_line_safe(line, '\0'))
		return (OK);
	else
		return (ERROR);
}

char	*add_newline(char *text)
{
	char	*tmp;

	if (text)
	{
		tmp = text;
		text = ft_strjoin(text, "\n");
		free(tmp);
		return (text);
	}
	else
		return (NULL);
}

char	*join_next_line(char *text, char *next_line)
{
	char	*tmp;

	if (text && next_line)
	{
		tmp = text;
		text = ft_strjoin(text, next_line);
		free(tmp);
		free(next_line);
		return (text);
	}
	else
		return (NULL);
}

char *read_wolf_syntax_file(const char *path)
{
	int file_descriptor;
	char *map_str;
	char **line;

	if (!(line = malloc(sizeof(char*))))
		return (ERROR);
	if (!(map_str = ft_strdup("\n")))
		return (ERROR);		////////////// free line
	if ((file_descriptor = open(path, O_RDONLY)) <= 0)
		return (ERROR);		////////////// free line + map_str
	while (ft_get_next_line(file_descriptor, line))
	{
		if (is_syntax_safe(*line))
			map_str = join_next_line(map_str, add_newline(*line));
		else
		{
			free(map_str);
			return (throw_error_str("map syntax error.."));
		}
	}
	free(line);
	return (map_str);
}

char	*new_flag(char *flag_name)
{
	char	*tmp;
	char	*flag;

	if (flag_name)
	{
		tmp = ft_strjoin("\n-", flag_name);
		flag = ft_strjoin(tmp, "\n");
		if (tmp)
			free(tmp);
		return (flag);
	}
	else
		return (NULL);
}
char	*select_flag(char *map_str, char *flag_name)
{
	char	*flag_start;
	char	*flag_end;
	char	*flag;
	
	if (!(flag = new_flag(flag_name)))
		return (ERROR);
	if (!(flag_start = ft_strstr(map_str, flag)))
		return (ERROR);		////// free flag
	flag_start += ft_strlen(flag);
	if ((flag_end = ft_strstr(flag_start, "\n-")))
		return (ft_strndup(flag_start, flag_end - flag_start));
	else
		return (ft_strdup(flag_start));
}

char	*get_key(char *wolf_data_line)
{
	char	*p;

	p = wolf_data_line;
	return (ft_strndup(p, ft_strstr(p, ": ") - p));
}

char	*get_value(char *wolf_data_line)
{
	char	*p;

	p = wolf_data_line;
	if (!is_wolf_data_line_safe(p, '\n'))
	{
		throw_error_str("get_value() has received bad data line..");
		return (NULL);
	}
	return (ft_strndup(ft_strstr(p, ":") + 2, ft_strstr(p, "\n")
			- (ft_strstr(p, ": ") + 2)));
}

char	**get_values(char *wolf_data_line, char	split)
{
	char	*p;
	char	*value;
	char	**values;

	p = wolf_data_line;
	value = get_value(p);
	values = ft_strsplit(value, split);
	if (value)
		free(value);
	return (values);
}

///////////////////////////////////////////////////////// text cursor

char	*ignore_char(char *text, char c)
{
	char	*p;

	p = text;
	while (p && *p && *p == c)
		p++;
	return (p);
}

char	*ignore_newlines(char *text)
{
	return (ignore_char(text, '\n'));
}

char	*ignore_spaces(char *text)
{
	return (ignore_char(text, ' '));
}

char	*next_line(char *text)
{
	return (ignore_newlines(ft_strstr(text, "\n") + 1));
}

///////////////////////////////////////////////////////// MAP PARSING

t_result parse_textures_list(t_map *self, char *textures_flag_str)
{
	t_texture_node	*new_node;
	char			*p;

	if (!init_list_head(&self->textures))
		return (ERROR);
	p = ignore_newlines(textures_flag_str);
	while (p && *p)
	{
		if (!(new_node = new_texture_node(get_key(p), get_value(p))))
			return (ERROR);
		list_add_entry(&new_node->node, &self->textures);
		p = next_line(p);
	}
	free(textures_flag_str);
	return (OK);
}

t_result parse_blocs_list(t_map *self, char *blocs_flag_str)
{
	t_bloc_node		*new_node;
	char			*p;

	if (!init_list_head(&self->blocs))
		return (ERROR);
	p = ignore_newlines(blocs_flag_str);
	while (p && *p)
	{
		if (!(new_node = new_bloc_node(get_key(p), get_values(p, ' '))))
			return (ERROR);
		list_add_entry(&new_node->node, &self->blocs);
		p = next_line(p);
	}
	free(blocs_flag_str);
	return (OK);
}

t_result parse_size(t_map *self, char *size_flag_str)
{
	int		height;
	int		width;
	char	*p;
	
	p = size_flag_str;
	if (!ft_strstr(p, "height: ") || !ft_strstr(p, "width: "))
		return (ERROR); /////////////////////// free size_flag_str
	height = ft_atoi(ft_strstr(p, "height: ") + ft_strlen("height: "));
	width = ft_atoi(ft_strstr(p, "width: ") + ft_strlen("width: "));
	free(size_flag_str);
	if (height < 3 || width < 3)
		return (ERROR);
	self->size.x = width;
	self->size.y = height;
	return (OK);
}

t_bloc_node	*is_key_belong_to_blocs_list(t_map *self, char key)
{
	t_list_head	*pos;
	t_list_head	*next;
	
	pos = (t_list_head*)&(self->blocs);
	next = pos->next;
	while ((pos = next) != (t_list_head*)&(self->blocs))
	{
		next = next->next;
		if (*(((t_bloc_node*)pos)->key) == key)
			return ((t_bloc_node*)pos);
	}
	return (ERROR);
}

t_texture_node	*is_key_belong_to_textures_list(t_map *self, char *key)
{
	t_list_head	*pos;
	t_list_head	*next;
	
	pos = (t_list_head*)&(self->textures);
	next = pos->next;
	while ((pos = next) != (t_list_head*)&(self->textures))
	{
		next = next->next;
		if (!ft_strcmp((((t_texture_node*)pos)->name), key))
			return ((t_texture_node*)pos);
	}
	return (ERROR);
}

t_result	add_wall(t_map *self, t_bloc_node *bloc, int x, int y)
{
	t_texture_node	*t;

	if (!(t = is_key_belong_to_textures_list(self, bloc->north_texture_name)))
		return (throw_result_str("failed to find north texture.."));
	self->map[x + y * self->size.x].north_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, bloc->east_texture_name)))
		return (throw_result_str("failed to find east texture.."));
	self->map[x + y * self->size.x].east_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, bloc->south_texture_name)))
		return (throw_result_str("failed to find south texture.."));
	self->map[x + y * self->size.x].south_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, bloc->west_texture_name)))
		return (throw_result_str("failed to find west texture.."));
	self->map[x + y * self->size.x].west_texture_ref = t->image;
	return (OK);
}

t_result	fill_map_row(t_map *self, char *row, int y)
{
	t_bloc_node	*bloc;
	int			x;

	if (!row || ft_strlen(row) != self->size.x)
		return (throw_result_str("bad number of character in map row.."));
	x = 0;
	while (row && row[x])
	{
		if (row[x] == ' ')
		{
			self->map[x + y * self->size.x].north_texture_ref = NULL;
			self->map[x + y * self->size.x].east_texture_ref = NULL;
			self->map[x + y * self->size.x].south_texture_ref = NULL;
			self->map[x + y * self->size.x].west_texture_ref = NULL;
		}
		else if ((bloc = is_key_belong_to_blocs_list(self, row[x])))
			add_wall(self, bloc, x, y);
		else
			return (throw_result_str("failed to find key in blocs list.."));
		x++;
	}
	return (OK);
}

t_result parse_map(t_map *self, char *map_flag_str)
{
	char	*p;
	int		columns_amount;

	if (!(self->map = malloc(sizeof(t_wall) * self->size.x * self->size.y)))
		return (throw_result_str("parse_map: failed to malloc map !"));
	p = ignore_newlines(map_flag_str);
	columns_amount = 0;
	while (p && *p)
	{
		if (!fill_map_row(self, get_value(p), columns_amount++))
			return (throw_result_str("failed to fill map row.."));
		p = next_line(p);
	}
	free(map_flag_str);
	return (OK);
}

t_result	init_map(t_map *self, const t_map_args *const args)
{
	char *map_file_str;

	if (!(map_file_str = read_wolf_syntax_file(args->path)))
		return (throw_result_str("read_wolf_file() bad syntax.."));
	if (!parse_textures_list(self, select_flag(map_file_str, "textures")))
		return (throw_result_str("failed to parse textures"));
	if (!parse_blocs_list(self, select_flag(map_file_str, "blocs")))
		return (throw_result_str("failed to parse blocs"));
	if (!parse_size(self, select_flag(map_file_str, "size")))
		return (throw_result_str("failed to parse size"));
	if (!parse_map(self, select_flag(map_file_str, "map")))
		return (throw_result_str("failed to parse map"));


		
	list_foreach(&self->textures, 0, list_print_texture); ///// debug
	list_foreach(&self->blocs, 0, list_print_bloc); ///// debug
	printf("x: %d y:%d\n", self->size.x, self->size.y);
	int i = -1;
	int j;
	while (++i < self->size.y)
	{
		j = -1;
		while(++j < self->size.y)
		{
			if (self->map[j + i * self->size.x].north_texture_ref)
				printf("a");
			else
				printf(" ");
		}
		printf("\n");
	}


	free(map_file_str);
	return (OK);
}