/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:45:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/25 19:28:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine/map.h"
#include "ft/str.h"
#include "maths/maths.h"
#include "engine/error.h"
#include "engine/parsing.h"

// t_result	is_wolf_flag_safe(char *line)
// {
// 	if (!line || !(*line))
// 		return (ERROR);
// 	line++;
// 	while (*line)
// 	{
// 		if (!ft_isalnum(*line) && *line != '_')
// 			return (ERROR);
// 		line++;
// 	}
// 	return (OK);
// }

// t_result	is_wolf_data_line_safe(char *line, char end)
// {
// 	while (line && *line && *line != ':' && *line != end)
// 	{
// 		if (!ft_isalnum(*line) && *line != '_')
// 			return (ERROR);
// 		line++;
// 	}
// 	if (!line || *line != ':' || line[1] != ' ')
// 		return (ERROR);
// 	else
// 		return (OK);
// }

// t_result	is_syntax_safe(char *line)
// {
// 	if (line && *line == '\0')
// 		return (OK);
// 	else if (line && *line == '-' && is_wolf_flag_safe(line))
// 		return (OK);
// 	else if (line && is_wolf_data_line_safe(line, '\0'))
// 		return (OK);
// 	else
// 		return (ERROR);
// }

// char *read_wolf_syntax_file(const char *path)
// {
// 	int		file_descriptor;
// 	char	*map_str;
// 	char	**line;

// 	if (!(line = malloc(sizeof(char*))))
// 		return (ERROR);
// 	if (!(map_str = ft_strdup("\n")))
// 		return (ERROR);		////////////// free line
// 	if ((file_descriptor = open(path, O_RDONLY)) <= 0)
// 		return (ERROR);		////////////// free line + map_str
// 	while (ft_get_next_line(file_descriptor, line))
// 	{
// 		if (is_syntax_safe(*line))
// 			map_str = join_next_line(map_str, add_newline(*line));
// 		else
// 		{
// 			free(map_str);
// 			return (throw_error_str("map syntax error.."));
// 		}
// 	}
// 	free(line);
// 	return (map_str);
// }

// char	*new_flag(char *flag_name)
// {
// 	char	*tmp;
// 	char	*flag;

// 	if (flag_name)
// 	{
// 		tmp = ft_strjoin("\n-", flag_name);
// 		flag = ft_strjoin(tmp, "\n");
// 		if (tmp)
// 			free(tmp);
// 		return (flag);
// 	}
// 	else
// 		return (NULL);
// }
// char	*select_flag(char *map_str, char *flag_name)
// {
// 	char	*flag_start;
// 	char	*flag_end;
// 	char	*flag;
	
// 	if (!(flag = new_flag(flag_name)))
// 		return (ERROR);
// 	if (!(flag_start = ft_strstr(map_str, flag)))
// 	{
// 		free(flag);
// 		return (ERROR);
// 	}
// 	flag_start += ft_strlen(flag);
// 	if ((flag_end = ft_strstr(flag_start, "\n-")))
// 		return (ft_strndup(flag_start, flag_end - flag_start));
// 	else
// 		return (ft_strdup(flag_start));
// }

// char	*get_key(char *wolf_data_line)
// {
// 	char	*p;

// 	p = wolf_data_line;
// 	return (ft_strndup(p, ft_strstr(p, ": ") - p));
// }

// char	*get_value(char *wolf_data_line)
// {
// 	char	*p;

// 	p = wolf_data_line;
// 	if (!is_wolf_data_line_safe(p, '\n'))
// 		return (throw_error_str("get_value() has received bad data line.."));
// 	return (ft_strndup(
// 		ft_strstr(p, ":") + 2,
// 		ft_strstr(p, "\n") - (ft_strstr(p, ": ") + 2)));
// }

// char	**get_values(char *wolf_data_line, char	split)
// {
// 	char	*p;
// 	char	*value;
// 	char	**values;

// 	p = wolf_data_line;
// 	if (!(value = get_value(p)))
// 		return (throw_error_str("failed to get value"));
// 	if (!(values = ft_strsplit(value, split)))
// 	{
// 		free(value);
// 		return (throw_error_str("failed to split values"));
// 	}
// 	free(value);
// 	return (values);
// }

// void	free_values(char **values)
// {
// 	size_t	i;

// 	i = 0;
// 	while (values[i])
// 		free(values[i++]);
// 	free(values);
// }

///////////////////////////////////////////////////////// text cursor

char	*skip_char(const char *text, const char c)
{
	if (!text)
		return (NULL);
	while (*text && *text == c)
		text++;
	return ((char*)text);
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

static void		free_textures_list(t_map *const self)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_texture_node	*node;

	pos = &self->textures;
	next = pos->next;
	while ((pos = next) != &self->textures)
	{
		next = next->next;
		node = (t_texture_node*)pos;
		free((char*)node->name);
		sfImage_destroy(node->image);
		free(node);
	}
}

static t_result	parse_textures_list(t_map *const self, char *textures_flag_str)
{
	t_texture_node	*new_node;
	char			*p;

	if (!textures_flag_str)
		return (throw_result_str("parse_textures_list(): "
			"invalid textures string"));
	init_list_head(&self->textures);
	p = skip_newlines(textures_flag_str);
	while (p && *p)
	{
		if (!(new_node = new_texture_node(wolf_get_key(p), wolf_get_value(p))))
		{
			free(textures_flag_str);
			free_textures_list(self);
			return (throw_result_str("parse_textures_list(): "
				"failed to create new texture node"));
		}
		list_add_entry(&new_node->node, &self->textures);
		p = next_line(p);
	}
	free(textures_flag_str);
	return (OK);
}

static void		free_blocks_list(t_map *const self)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_block_node	*node;

	pos = &self->textures;
	next = pos->next;
	while ((pos = next) != &self->blocks)
	{
		next = next->next;
		node = (t_block_node*)pos;
		free((char*)node->key);
		free((char*)node->north_texture_name);
		free((char*)node->east_texture_name);
		free((char*)node->south_texture_name);
		free((char*)node->west_texture_name);
		free(node);
	}
}

static t_result	parse_blocks_list(t_map *self, char *blocks_flag_str)
{
	t_block_node	*new_node;
	char			*p;

	if (!blocks_flag_str)
		return (throw_result_str("parse_blocks_list(): "
			"invalid blocks string"));
	init_list_head(&self->blocks);
	p = skip_newlines(blocks_flag_str);
	while (p && *p)
	{
		if (!(new_node = new_block_node(wolf_get_key(p),
			wolf_get_values(p, ' '))))
		{
			free(blocks_flag_str);
			free_blocks_list(self);
			return (throw_result_str("parse_blocks_list(): "
				"failed to create new block node"));
		}
		list_add_entry(&new_node->node, &self->blocks);
		p = next_line(p);
	}
	free(blocks_flag_str);
	return (OK);
}

t_result parse_size(t_map *self, char *size_flag_str)
{
	int		height;
	int		width;
	char	*p;

	if (!size_flag_str)
		return (ERROR);
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

t_block_node	*is_key_belong_to_blocks_list(t_map *self, char key)
{
	t_list_head	*pos;
	t_list_head	*next;
	
	pos = (t_list_head*)&(self->blocks);
	next = pos->next;
	while ((pos = next) != (t_list_head*)&(self->blocks))
	{
		next = next->next;
		if (*(((t_block_node*)pos)->key) == key)
			return ((t_block_node*)pos);
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

t_result	add_wall(t_map *self, t_block_node *block, int x, int y)
{
	t_texture_node	*t;

	if (!(t = is_key_belong_to_textures_list(self, block->north_texture_name)))
		return (throw_result_str("failed to find north texture.."));
	self->map[x + y * self->size.x].north_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, block->east_texture_name)))
		return (throw_result_str("failed to find east texture.."));
	self->map[x + y * self->size.x].east_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, block->south_texture_name)))
		return (throw_result_str("failed to find south texture.."));
	self->map[x + y * self->size.x].south_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, block->west_texture_name)))
		return (throw_result_str("failed to find west texture.."));
	self->map[x + y * self->size.x].west_texture_ref = t->image;
	return (OK);
}

t_result	fill_map_row(t_map *self, char *row, int y)
{
	t_block_node	*block;
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
		else if ((block = is_key_belong_to_blocks_list(self, row[x])))
			add_wall(self, block, x, y);
		else
			return (throw_result_str("failed to find key in blocks list.."));
		x++;
	}
	return (OK);
}

t_result parse_map(t_map *self, char *map_flag_str)
{
	char	*p;
	size_t	columns_amount;

	if (!map_flag_str)
		return (ERROR);
	if (!(self->map = malloc(sizeof(t_wall) * self->size.x * self->size.y)))
	{
		free(map_flag_str);
		return (throw_result_str("parse_map: failed to malloc map !"));
	}
	p = skip_newlines(map_flag_str);
	columns_amount = 0;
	while (p && *p)
	{
		if (!fill_map_row(self, wolf_get_value(p), columns_amount++))
		{
			free(map_flag_str);
			free(self->map);
			return (throw_result_str("failed to fill map row.."));
		}
		p = next_line(p);
	}
	free(map_flag_str);
	return (OK);
}

t_result	init_map(t_map *self, const t_map_args *const args)
{
	char 	*map_file_str;

	init_module(&self->module);
	if (!(map_file_str = wolf_read_file(args->path)))
		return (throw_result_str("init_map(): ""failed to read file"));
	if (!parse_textures_list(self, wolf_select_flag(map_file_str, "textures")))
	{
		free(map_file_str);
		return (throw_result_str("init_map(): ""failed to parse textures"));
	}
	if (!parse_blocks_list(self, wolf_select_flag(map_file_str, "blocks")))
	{
		free(map_file_str);
		return (throw_result_str("init_map(): ""failed to parse blocks"));
	}
	if (!parse_size(self, wolf_select_flag(map_file_str, "size")))
	{
		free(map_file_str);
		return (throw_result_str("init_map(): ""failed to parse size"));
	}
	if (!parse_map(self, wolf_select_flag(map_file_str, "map")))
	{
		free(map_file_str);
		return (throw_result_str("init_map(): ""failed to parse map"));
	}
	free(map_file_str);
	return (OK);
}