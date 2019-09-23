/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:50:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/23 19:14:52 by lbenard          ###   ########.fr       */
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
	const t_image	*texture;
	float			texture_ratio;
}						t_ray;

t_ray					ft_ray(const float distance,
							const t_image *texture,
							const float texture_ratio);

typedef struct			s_angle
{
	float	rad;
	float	cos;
	float	sin;
	float	tan;
}						t_angle;

t_angle					ft_angle(float rad);

typedef struct			s_raycasting_renderer
{
	t_module	module;
	t_map		*const map;
	t_ray		*const columns;
	size_t		columns_number;
	t_vec2f		position;
	float		direction;
	float		fov;
}						t_raycasting_renderer;

typedef struct			s_raycasting_renderer_args
{
	t_usize	window_size;
	t_map	*map;
}						t_raycasting_renderer_args;

t_stack_module_factory	raycasting_renderer(const t_usize window_size,
							t_map *const map);

t_result				init_raycasting_renderer(
							t_raycasting_renderer *const self,
							const t_raycasting_renderer_args *const args);
void					raycasting_renderer_update(
							const t_raycasting_renderer *const self);
void					destroy_raycasting_renderer(
							t_raycasting_renderer *const self);

#endif
