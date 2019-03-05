/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/05 11:27:40 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

int		sign(void *number, char type)
{
	if (type == 'i')
		return (*(int*)number >= 0 ? 1 : -1);
	if (type == 'f')
		return (*(float*)number >= 0.0f ? 1 : -1);
	if (type == 'd')
		return (*(double*)number >= 0.0 ? 1 : -1);
	return (0);
}

void    render_column(t_param *p, float distance, int column)
{
	int		j;

	j = -1;
	while (++j < (int)(((float)p->mlx.height * 0.5) / distance))
	{
		if (column > p->mlx.width * p->map.zoom || (int)(0.5 * p->mlx.height - j) > p->mlx.height * p->map.zoom)
			p->mlx.pixels[column + (int)(0.5 * p->mlx.height - j) * p->mlx.width] = 0x00FFFFFF;//ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
		p->mlx.pixels[column + (int)(0.5 * p->mlx.height + j) * p->mlx.width] = 0x00FFFFFF;//ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
	}
}

void	render_2d_visible_surface(t_param *p, float x, float y, int color)
{
	float	i;
	float	j;

	i = x * ((float)p->mlx.width * p->map.zoom) / (float)p->map.width;
	j = y * ((float)p->mlx.height * p->map.zoom) / (float)p->map.height;
	i = i > 0 ? i : -i;
	j = j > 0 ? j : -j;
	p->mlx.pixels[(int)i + (int)j * p->mlx.width] = color;
}

float	search_horizontal_intersection(t_param *p, float cosx, float siny, float direction)
{
	float	x;
	float	y;
	float	tx;
	int		signy;

	x = p->hero.x;
	y = p->hero.y;
	signy = sign(&siny, 'f');
	tx = 1.0 / tan(direction);
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)y == (int)p->hero.y)
	{
		x += 0.01 * cosx;
		y += 0.01 * siny;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x + (int)y * p->map.width)])
			break ;
		x += tx * signy;
		y += signy;
	}
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
		render_2d_visible_surface(p, x, y, 0x00FF0000);
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		return (sqrt(x * x + y * y));
	}
	return (-42);
}

float	search_vertical_intersection(t_param *p, float cosx, float siny, float direction)
{
	float	x;
	float	y;
	float	ty;
	int		signx;

	x = p->hero.x;
	y = p->hero.y;
	signx = sign(&cosx, 'f');
	ty = tan(direction);
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)x == (int)p->hero.x)
	{
		x += 0.01 * cosx;
		y += 0.01 * siny;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x + (int)y * p->map.width)])
			break ;
		x += signx;
		y += ty * signx;
	}
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
		render_2d_visible_surface(p, x, y, 0x000000FF);
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		return (sqrt(x * x + y * y));
	}
	return (-42);
}

int	search_wall(t_param *p, float direction, float *distance)
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
	else if (distancex < 0)
		*distance = distancey;
	else if (distancey < 0)
		*distance = distancex;
	else if (distancex < distancey)
		*distance = distancex;
	else
		*distance = distancey;
	// *distance *= siny;
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
		if (search_wall(p, direction, &distance))
			render_column(p, distance, column_number);
		direction += shift;
	}
}