/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:38:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/23 19:19:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "engine/module.h"
# include "types.h"
# include "sizes/usize.h"
# include "maths/vec2f.h"
# include "engine/image.h"

typedef struct			s_wall
{
	t_image	*north_texture_ref;
	t_image	*east_texture_ref;
	t_image	*south_texture_ref;
	t_image	*west_texture_ref;
}						t_wall;

typedef struct			s_texture_node
{
	t_list_head	node;
	const char	*name;
	t_image		*image;
}						t_texture_node;
t_texture_node			*new_texture_node(const char *name,
							const char *const path);

typedef struct			s_bloc_node
{
	t_list_head	node;
	const char	*key;
	const char	*north_texture_name;
	const char	*east_texture_name;
	const char	*south_texture_name;
	const char	*west_texture_name;
}						t_bloc_node;
t_bloc_node  *new_bloc_node(const char *key, char **values);

typedef struct			s_map
{
	t_module	module;
	t_list_head textures;
	t_list_head blocs;
	t_usize		size;
	t_wall		*map;
}						t_map;

typedef struct			s_map_args
{
	const char	*path;
}						t_map_args;

t_stack_module_factory	map(const char *const path);

t_result				init_map(t_map *self, const t_map_args *const args);
void					destroy_map(t_map *self);

#endif