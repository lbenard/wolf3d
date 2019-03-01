/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/01 18:06:31 by pp               ###   ########.fr       */
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
			p->mlx.pixels[column + (int)(0.5 * p->mlx.height - j) * p->mlx.width] = ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
		p->mlx.pixels[column + (int)(0.5 * p->mlx.height + j) * p->mlx.width] = ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
	}
}

void	render_2d_visible_surface(t_param *p, float x, float y)
{
	float	i;
	float	j;

	i = x * ((float)p->mlx.width * p->map.zoom) / (float)p->map.width;
	j = y * ((float)p->mlx.height * p->map.zoom) / (float)p->map.height;
	i = i > 0 ? i : -i;
	j = j > 0 ? j : -j;
	p->mlx.pixels[(int)i + (int)j * p->mlx.width] = 0x00FF0000;
}



int	search_wall(t_param *p, float direction, float *distance)
{
	float	x;
	float	y;
	float	cosx;
	float	siny;
	float	rest;
	float	tx;
	float	ty;

	cosx = cos(direction);
	siny = sin(direction);
	x = p->hero.x;
	y = p->hero.y;
	ty = tan(direction);
	tx = 1.0f / ty;
	// while (x < next_intersection_horizontale)
	//		x += 0.01 * cosx;
	// while (map[x + y * width] = 0)
	//		x += tx;
	//		x++;
	// while (y < next_vertical_intersection)
	//		y += 0,01 * siny;
	// while (map[x + y * width] = 0)
	//		y += ty
	//		x++;
	//  merdetouta l'heure j'ai fais un truc cool et j'avais juste a mettre -1 pour aue ca marche...
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x + (int)y * p->map.width)])
			break ;
		x += 0.01f * cosx;
		y += 0.01f * siny;
	}
	if (p->map.map[(int)(x + (int)y * p->map.width)])
	{
		render_2d_visible_surface(p, x, y);
		x -= p->hero.x;
		y -= p->hero.y;
		*distance = sqrt(x * x + y * y);
		*distance = *distance < 1 ? 1 : *distance;
		return (1);
	}
	return (0);
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
// cos_direction = cos(direction);
			// cos_direction *= cos_direction > 0 ? 1 : -1;
			// sin_direction = sin(direction);
			// sin_direction *= sin_direction > 0 ? 1 : -1;
			// if (cos_direction > sin_direction)
			// 	distance *= cos_direction;
			// else
			// 	distance *= sin_direction