/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:50:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/12 23:53:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <SFML/Graphics.h>
# include "types.h"
# include "containers/list.h"
# include "engine/map.h"
# include "engine/sprite.h"
# include "maths/vec2f.h"

typedef enum	e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_direction;

typedef struct	s_ray
{
	float	distance;
	t_u8	texture;
	float	texture_ratio;
}				t_ray;

t_ray			ft_ray(const float distance,
					const t_u8 texture,
					const float texture_ratio);

typedef struct	s_angle
{
	float	rad;
	float	cos;
	float	sin;
	float	tan;
}				t_angle;

t_angle			ft_angle(float rad);

typedef struct	s_raycasting_renderer
{
	t_map		*const map;
	t_ray		*const columns;
	size_t		columns_number;
	t_vec2f		position;
	float		direction;
	float		fov;
	// t_list_head	sprites;
}				t_raycasting_renderer;

t_result		init_raycasting_renderer(
					t_raycasting_renderer *const self,
					const t_usize window_size,
					t_map *const map);
void			raycasting_renderer_update(
					const t_raycasting_renderer *const self);
void			destroy_raycasting_renderer(t_raycasting_renderer *const self);

#endif
