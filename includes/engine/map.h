/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:38:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:03:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "engine/module.h"
# include "types.h"
# include "sizes/usize.h"
# include "maths/vec2f.h"

typedef struct			s_wall
{
	t_u8	north_texture_id;
	t_u8	east_texture_id;
	t_u8	south_texture_id;
	t_u8	west_texture_id;
}						t_wall;

typedef struct			s_map
{
	t_module	module;
	t_wall		*map;
	t_usize		size;
	t_vec2f		spawn_position;
}						t_map;

typedef struct			s_map_args
{
	const char	*path;
}						t_map_args;

t_stack_module_factory	map(const char *const path);

t_result				init_map(t_map *self, const t_map_args *const args);
void					destroy_map(t_map *self);

#endif