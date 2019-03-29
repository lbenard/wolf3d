/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/29 16:13:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

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
	int		j;
	double	d = distance > 1.5 ? distance : 1.5;
	int		l = 255.0 / d;
	int		wall_height;

	wall_height = (int)(((double)p->mlx.height / 2.0) / distance);

	j = -wall_height;
	while (++j < wall_height)
	{
		p->mlx.pixels[column + (int)(0.5 * p->mlx.height + j) * p->mlx.width]
		= render_texture(p, j, wall_height);//l * 256 * 256 + l * 256 + l;//0x00FFFFFF;
	}
}

void	find_distance(t_param *p)
{
	if (!p->ray.v_hit || (p->ray.h_hit 
		&& p->ray.dist_to_h_wall < p->ray.dist_to_v_wall))
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
	p->ray.distance = p->ray.distance < 1 ? 1 : p->ray.distance;
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