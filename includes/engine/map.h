/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:38:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/12 23:53:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "types.h"
# include "sizes/usize.h"
# include "maths/vec2f.h"

typedef struct	s_wall
{
	t_u8	north_texture_id;
	t_u8	east_texture_id;
	t_u8	south_texture_id;
	t_u8	west_texture_id;
}				t_wall;

typedef struct	s_map
{
	t_wall	*map;
	t_usize	size;
	t_vec2f	spawn_position;
}				t_map;

t_result	init_map(t_map *self, const char *const path);
void		destroy_map(t_map *self);

#endif