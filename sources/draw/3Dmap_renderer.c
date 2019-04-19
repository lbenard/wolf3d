/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/04/15 19:40:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

int		add_shadow(int color, double distance)
{
	int		r;
	int		g;
	int		b;

	if (distance > 100)
	       	distance = 100;
	r = color >> 16;
	g = (color >> 8) - (r << 8);
	b = color - (r << 16) - (g << 8);
	r /= distance;
	g /= distance;
	b /= distance;
	return((r << 16) + (g << 8) + b);
}

int	render_texture(t_param *p, double j, double height)
{
	double	i_column;
	double	i_line;

	if (p->ray.h_hit)
		i_column = p->wall.x - (double)((int)p->wall.x);
	else
		i_column = p->wall.y - (double)((int)p->wall.y);
	i_column *= p->map.texture->head.width;
	i_line = (double)p->map.texture->head.height * 0.5;
	i_line += (j / height) * i_line;
	return (p->map.texture->pixels[(int)(i_column + ((int)i_line * p->map.texture->head.width))]);
}

void    render_column(t_param *p, double distance, int column)
{
	int		wall_height;
	int		wall_height_max;
	int		j;
	double	d = distance > 1 ? distance : 1;

	wall_height = (int)(((double)p->mlx.height / 2.0) / distance);
	wall_height_max = (int)((double)p->mlx.height / 2.0);
	if (distance > 1)
		j = -wall_height;
	else
		j = -wall_height_max - 1;
	while (++j < (int)(((double)p->mlx.height / 2.0)) && j < wall_height)
	{
		p->mlx.pixels[column + (int)(0.5 * p->mlx.height + j) * p->mlx.width]
		= add_shadow(render_texture(p, j, wall_height), d);
	}
}

void	find_distance(t_param *p)
{
	if (/*!p->ray.v_hit || (p->ray.h_hit 
		&&*/( p->ray.dist_to_h_wall < p->ray.dist_to_v_wall))
	{
		p->ray.distance = p->ray.dist_to_h_wall * p->ray.fisheye_correction;
		p->wall.x = p->horizontal_wall.x;
		p->wall.y = p->horizontal_wall.y;
		p->ray.v_hit = 0;
	}
	else
	{
		p->ray.distance = p->ray.dist_to_v_wall * p->ray.fisheye_correction;
		p->wall.x = p->vertical_wall.x;
		p->wall.y = p->vertical_wall.y;
		p->ray.h_hit = 0;
	}
	//p->ray.distance = p->ray.distance < 1 ? 1 : p->ray.distance;
}

int		search_wall(t_param *p, double direction)
{
	p->ray.h_hit = 0;
	p->ray.v_hit = 0;
	p->ray.cos = cos(direction);
	p->ray.sin = sin(direction);
	p->ray.tan = tan(direction);
	search_horizontal_wall(p, (double)p->hero.x, (double)p->hero.y);
	search_vertical_wall(p, (double)p->hero.x, (double)p->hero.y);
	find_distance(p);
	if (!p->ray.h_hit && !p->ray.v_hit)
		return (0);
	return (1);
}

void	render_3d_map(t_param *p)
{
	int		column_number;
	double	direction;
	double	shift;

	shift = (M_PI / 3.0f) / (double)p->mlx.width;
	direction = p->hero.vector_direction - (M_PI / 6.0f);
	column_number = -1;
	while (++column_number < p->mlx.width)
	{
		p->ray.fisheye_correction = cos(-M_PI / 6.0f + column_number * shift);
		if (search_wall(p, direction))
			render_column(p, p->ray.distance, column_number);
		p->map.rays[column_number].x = p->wall.x;
		p->map.rays[column_number].y = p->wall.y;
		direction += shift;
	}
}
