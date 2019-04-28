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
#include "../includes/obstacle.h"
#include "../includes/rayon.h"
#include "../includes/bitmap.h"
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

int	texture(t_bitmap_image *texture, t_obstacle obstacle, double line_ratio)
{
	double	column_ratio;
	int	column;
	int	line;

	line = line_ratio * (double)texture->head.height;
	if (obstacle.direction == 'N' || obstacle.direction == 'S')
		column_ratio = obstacle.position.x - (int)obstacle.position.x;
	else
		column_ratio = obstacle.position.y - (int)obstacle.position.y;
	column = column_ratio * (double)texture->head.width;
	return (texture->pixels[column + line * texture->head.width]);
}

void	render_column(t_param *p, t_obstacle obs, int col)
{
	double	line_ratio;
	int	y_start;
	int	i;
	t_obstacle *obstacle;

	obstacle = &obs;
	while (obstacle)
	{
		y_start = (W_HEIGHT - obstacle->size) * 0.5;
		i = -1;
		while (++i < obstacle->size)
		{
			line_ratio = (double)i / (double)obstacle->size;
			p->mlx.pixels[col + (y_start + i) * W_WIDTH] =
			add_shadow (texture(p->map.texture, *obstacle, line_ratio),
				obstacle->distance);
		}
		obstacle = obstacle->next;
	}
}

void	draw_3dmap(t_param *p, t_obstacle *obstacle)
{	
	int	column_number;
	
	column_number = -1;
	while (++column_number < W_WIDTH)
		render_column(p, obstacle[column_number], column_number);
}
