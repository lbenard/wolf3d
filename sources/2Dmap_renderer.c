/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:33:43 by pp                #+#    #+#             */
/*   Updated: 2019/02/22 19:06:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>

void	render_hero_vector(t_param *p, int x, int y)
{
	t_point point[2];

	point[0].x = x;
	point[0].z = y;
	point[1].x = x + 20 * cos(p->hero.vector_direction);
	point[1].z = y + 20 * sin(p->hero.vector_direction);
	bresenham(p, point);
}

void	render_hero(t_param *p)
{
	int		x;
	int		y;

	x = (p->hero.x * ((float)p->mlx.width * p->map.zoom)) / (float)p->map.width;
	y = (p->hero.y * ((float)p->mlx.height * p->map.zoom)) / (float)p->map.height;
	render_hero_vector(p, x, y);
	p->mlx.pixels[x + y * p->mlx.width] = 0x00FF0000;
	p->mlx.pixels[x + 1 + y * p->mlx.width] = 0x00FF0000;
	p->mlx.pixels[x - 1 + y * p->mlx.width] = 0x00FF0000;
	p->mlx.pixels[x + (y + 1) * p->mlx.width] = 0x00FF0000;
	p->mlx.pixels[x + (y - 1) * p->mlx.width] = 0x00FF0000;
}

void     render_2d_map(t_param *p)
{
    int     i;
    int     j;
    int     k;
    int     l;

    i = -1;
    while (++i < p->mlx.height * 0.2)
    {
        j = -1;
        while (++j < p->mlx.width * 0.2)
        {
            k = ((float)i / ((float)p->mlx.height * 0.2)) * (float)p->map.height;
            l = ((float)j / ((float)p->mlx.width * 0.2)) * (float)p->map.width;
			if (p->map.map[(int)(l + k * p->map.width)])
                p->mlx.pixels[j + i * p->mlx.width] = 0x00AAAAAA; 
            else
                p->mlx.pixels[j + i * p->mlx.width] = 0x00FFFFFF;       
        }
    }
	render_hero(p);
}