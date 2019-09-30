/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:45:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/30 17:36:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "engine/map.h"
#include "ft/str.h"
#include "maths/maths.h"
#include "maths/vec2d.h"
#include "engine/error.h"
#include "engine/parsing.h"

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
		return (throw_result_str("parse_textures_list()",
			"invalid textures string"));
	init_list_head(&self->textures);
	p = skip_newlines(textures_flag_str);
	while (p && *p)
	{
		if (!(new_node = new_texture_node(wolf_get_key(p), wolf_get_value(p))))
		{
			free(textures_flag_str);
			free_textures_list(self);
			return (throw_result_str("parse_textures_list()",
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
		return (throw_result_str("parse_blocks_list()",
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
			return (throw_result_str("parse_blocks_list()",
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
	return (NULL);
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
	return (NULL);
}

t_result	add_wall(t_map *self, t_block_node *block, int x, int y)
{
	t_texture_node	*t;

	if (!(t = is_key_belong_to_textures_list(self, block->north_texture_name)))
		return (throw_result_str("add_wall()",
			"failed to find north texture"));
	self->map[x + y * self->size.x].north_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, block->east_texture_name)))
		return (throw_result_str("add_wall()",
			"failed to find east texture"));
	self->map[x + y * self->size.x].east_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, block->south_texture_name)))
		return (throw_result_str("add_wall()",
			"failed to find south texture"));
	self->map[x + y * self->size.x].south_texture_ref = t->image;
	if (!(t = is_key_belong_to_textures_list(self, block->west_texture_name)))
		return (throw_result_str("add_wall()",
			"failed to find west texture"));
	self->map[x + y * self->size.x].west_texture_ref = t->image;
	return (OK);
}

t_result	fill_map_row(t_map *self, char *row, int y)
{
	t_block_node	*block;
	int			x;

	if (!row || ft_strlen(row) != self->size.x)
		return (throw_result_str("fill_map_row()",
			"bad number of characters in map row"));
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
			return (throw_result_str("fill_map_row()",
				"failed to find key in blocks list"));
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
		return (throw_result_str("parse_map()", "failed to allocate map"));
	}
	p = skip_newlines(map_flag_str);
	columns_amount = 0;
	while (p && *p)
	{
		if (!fill_map_row(self, wolf_get_value(p), columns_amount++))
		{
			free(map_flag_str);
			free(self->map);
			return (throw_result_str("parse_map()", "failed to fill map row"));
		}
		p = next_line(p);
	}
	free(map_flag_str);
	return (OK);
}

int	ft_strsplit_length(char **strings)
{
	int	length;

	length = 0;
	while (strings && strings[length])
		length++;
	return (length);
}

t_result parse_player(t_map *self, char *player_flag_str)
{
	char	**spawn_str;

	spawn_str = wolf_get_values(ft_strstr(player_flag_str, "spawn: "), ' ');
	if (!spawn_str || ft_strsplit_length(spawn_str) != 2)
		return (throw_result_str("parse_player()", "bad player_spawn data"));
	else
		self->spawn = ft_vec2d(ft_atof(spawn_str[0]), ft_atof(spawn_str[1]));
	free(spawn_str);
	free(player_flag_str);
	return (OK);
}

t_result	init_map(t_map *self, const t_map_args *const args)
{
	char 	*map_file_str;

	init_module(&self->module);
	if (!(map_file_str = wolf_read_file(args->path)))
		return (throw_result_str("init_map()", "failed to read file"));
	if (!parse_textures_list(self, wolf_select_flag(map_file_str, "textures")))
	{
		free(map_file_str);
		return (throw_result_str("init_map()", "failed to parse textures"));
	}
	if (!parse_blocks_list(self, wolf_select_flag(map_file_str, "blocks")))
	{
		free(map_file_str);
		return (throw_result_str("init_map()", "failed to parse blocks"));
	}
	if (!parse_size(self, wolf_select_flag(map_file_str, "size")))
	{
		free(map_file_str);
		return (throw_result_str("init_map()", "failed to parse size"));
	}
	if (!parse_map(self, wolf_select_flag(map_file_str, "map")))
	{
		free(map_file_str);
		return (throw_result_str("init_map()", "failed to parse map"));
	}
	if (!parse_player(self, wolf_select_flag(map_file_str, "player")))
	{
		free(map_file_str);
		return (throw_result_str("init_map()", "failed to parse player"));
	}
	free(map_file_str);
	return (OK);
}