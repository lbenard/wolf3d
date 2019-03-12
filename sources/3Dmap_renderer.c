/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/12 11:56:30 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"


void    render_column(t_param *p, float distance, int column)
{
	int		j;

	j = -1;
	while (++j < (int)(((float)p->mlx.height * 0.5) / distance))
	{
		if (column > p->mlx.width * p->map.zoom || (int)(0.5 * p->mlx.height - j) > p->mlx.height * p->map.zoom)
			p->mlx.pixels[column + (int)(0.5 * p->mlx.height - j) * p->mlx.width] = 0x00FFFFFF;
		p->mlx.pixels[column + (int)(0.5 * p->mlx.height + j) * p->mlx.width] = 0x00FFFFFF;
	}
}

void	render_2d_visible_surface(t_param *p, t_point wall, int color)
{
	t_point point[2];
	float	i;
	float	j;

	i = wall.x * ((float)p->mlx.width * p->map.zoom) / (float)p->map.width;
	j = wall.y * ((float)p->mlx.height * p->map.zoom) / (float)p->map.height;
	i = i > 0 ? i : -i;
	j = j > 0 ? j : -j;
	point[0].x = p->hero.x * ((float)p->mlx.width * p->map.zoom) / (float)p->map.width;
	point[0].z = p->hero.y * ((float)p->mlx.height * p->map.zoom) / (float)p->map.height;
	point[1].x = i;
	point[1].z = j;
	bresenham(p, point, color);
}

void	find_distance(t_param *p)
{
	t_point	wall;

	if (!p->view.h_hit	|| (p->view.h_hit 
		&& p->view.dist_to_v_wall < p->view.dist_to_h_wall))
	{
		p->view.distance = p->view.dist_to_v_wall * p->view.fisheye_correction;
		wall.x = p->horizontal_wall.x;
		wall.y = p->horizontal_wall.y;
	}
	else
	{
		p->view.distance = p->view.dist_to_h_wall * p->view.fisheye_correction;
		wall.x = p->vertical_wall.x;
		wall.y = p->vertical_wall.y;
	}		
	render_2d_visible_surface(p, wall, 0x00FF0000);
	p->view.distance = p->view.distance < 1 ? 1 : p->view.distance;
}

int	search_wall(t_param *p, float direction, float *distance)
{
	p->view.h_hit = 0;
	p->view.v_hit = 0;
	p->view.cos = cos(direction);
	p->view.cos = sin(direction);
	p->view.tan = tan(direction);
	search_horizontal_intersection(p, direction);
	search_vertical_intersection(p, direction);
	if (!p->view.h_hit && !p->view.v_hit)
		return (0);
	else
		find_distance(p);
	return (1);
}

void	render_3d_map(t_param *p)
{
	float	direction;
	float	distance;
	float	shift;
	int		column_number;

	shift = (M_PI / 3.0f) / (float)p->mlx.width;
	direction = p->hero.vector_direction - M_PI / 6.0f;
	column_number = -1;
	while (++column_number < p->mlx.width)
	{
		if (search_wall(p, direction, &distance, -M_PI / 6.0f + column_number * shift))
			render_column(p, distance, column_number);
		direction += shift;
	}
}