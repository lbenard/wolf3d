/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:50:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 22:21:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "engine/module.h"
# include <SFML/Graphics.h>
# include "types.h"
# include "containers/list.h"
# include "engine/map.h"
# include "maths/vec2f.h"

typedef enum			e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}						t_direction;

typedef struct			s_ray
{
	float			distance;
	float			fisheye;
	t_vec2f			hit_position;
	const t_image	*texture;
	float			texture_ratio;
}						t_ray;

t_ray					ft_ray(const t_vec2f player_position,
							const t_vec2f hit_position,
							const t_image *texture,
							const float texture_ratio);
t_bool					is_ray_in_map(const t_vec2f pos,
							const t_map *const map);
const t_image			*ray_hitting_texture(const t_map *const map,
							const t_vec2f pos,
							const t_direction direction,
							const t_vec2f shift);

typedef struct			s_angle
{
	float	rad;
	float	cos;
	float	sin;
	float	tan;
}						t_angle;

t_angle					ft_angle(float rad);

typedef struct			s_raycasting
{
	t_module	module;
	t_map		*const map;
	t_ray		*const columns;
	t_ray		middle;
	size_t		columns_number;
	t_vec2f		position;
	float		direction;
	float		fov;
}						t_raycasting;

typedef struct			s_raycasting_args
{
	t_usize	window_size;
	t_map	*map;
}						t_raycasting_args;

t_stack_module_factory	raycasting(const t_usize window_size, t_map *const map);

t_result				init_raycasting(t_raycasting *const self,
							const t_raycasting_args *const args);
void					raycasting_update(t_raycasting *const self);
void					destroy_raycasting(t_raycasting *const self);

#endif
