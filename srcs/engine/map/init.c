/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:45:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/23 20:31:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine/map.h"
#include "ft/str.h"
#include "maths/maths.h"
#include "engine/error.h"

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

char	*skip_char(char *text, char c)
{
	char	*p;

	p = text;
	while (p && *p && *p == c)
		p++;
	return (p);
}

char	*skip_newlines(char *text)
{
	return (skip_char(text, '\n'));
}

char	*skip_spaces(char *text)
{
	return (skip_char(text, ' '));
}

char	*next_line(char *text)
{
	return (skip_newlines(ft_strstr(text, "\n") + 1));
}

///////////////////////////////////////////////////////// MAP PARSING

t_result parse_textures_list(t_map *self, char *textures_flag_str)
{
	t_texture_node	*new_node;
	char			*p;

	if (!init_list_head(&self->textures))
		return (ERROR);
	p = skip_newlines(textures_flag_str);
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
	p = skip_newlines(blocs_flag_str);
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

t_texture_node	*is_key_belong_to_textures_list(t_map *self, const char *key)
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
	p = skip_newlines(map_flag_str);
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
	char 	*map_file_str;

	init_module(&self->module);
	if (!(map_file_str = read_wolf_syntax_file(args->path)))
		return (throw_result_str("read_wolf_file() bad syntax.."));
	if (!parse_textures_list(self, select_flag(map_file_str, "textures")))
	{
		free(map_file_str);
		return (throw_result_str("failed to parse textures"));
	}
	if (!parse_blocs_list(self, select_flag(map_file_str, "blocs")))
	{
		free(map_file_str);
		return (throw_result_str("failed to parse blocs"));
	}
	if (!parse_size(self, select_flag(map_file_str, "size")))
	{
		free(map_file_str);
		return (throw_result_str("failed to parse size"));
	}
	if (!parse_map(self, select_flag(map_file_str, "map")))
	{
		free(map_file_str);
		return (throw_result_str("failed to parse map"));
	}
	free(map_file_str);
	return (OK);
}