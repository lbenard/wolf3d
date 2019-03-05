/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/05 20:03:57 by ppetitea         ###   ########.fr       */
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

void	render_2d_visible_surface(t_param *p, float x, float y, int color)
{
	t_point point[2];
	float	i;
	float	j;

	i = x * ((float)p->mlx.width * p->map.zoom) / (float)p->map.width;
	j = y * ((float)p->mlx.height * p->map.zoom) / (float)p->map.height;
	i = i > 0 ? i : -i;
	j = j > 0 ? j : -j;
	point[0].x = p->hero.x;
	point[0].y = p->hero.y;
	point[1].x = i;
	point[1].y = j;
	bresenham(p, point, color);
	//p->mlx.pixels[(int)i + (int)j * p->mlx.width] = color;
}

int	search_wall(t_param *p, float direction, float *distance, float shift)
{
	float	distancex;
	float	distancey;
	float	cosx;
	float	siny;

	cosx = cos(direction);
	siny = sin(direction);
	distancex = search_horizontal_intersection(p, cosx, siny, direction);
	distancey = search_vertical_intersection(p, cosx, siny, direction);
	if (distancex < 0 && distancey < 0)
		return (0);
	else if (distancex < 0 || (distancex > 0 && distancey > 0 && distancey < distancex))
		*distance = distancey * cos(shift);
	else
		*distance = distancex * cos(shift);
	*distance = *distance < 1 ? 1 : *distance;
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