/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:33:43 by pp                #+#    #+#             */
/*   Updated: 2019/03/12 18:03:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>

void	render_2d_visible_surface(t_param *p, int color)
{
	t_point point[2];
	int		column;
	double	x;
	double	y;
	
	column = -1;
	while (++column < p->mlx.width)
	{
		point[0].x = p->hero.position.x * p->map.w_ratio;
		point[0].z = p->hero.position.y * p->map.h_ratio;
		x = p->obstacle[column].position.x * p->map.w_ratio;
		y = p->obstacle[column].position.y * p->map.h_ratio;
		x = x > 0 ? x : -x;
		y = y > 0 ? y : -y;
		point[1].x = x;
		point[1].z = y;
		bresenham(p, point, color);
	}
}

void	render_hero_vector(t_param *p)
{
	float	x;
	float	y;
	float	cos_hvd;
	float	sin_hvd;
	int   i;

	cos_hvd = 0.05f * cos(p->hero.view.direction);
	sin_hvd = 0.05f * sin(p->hero.view.direction);
	i = -1;
	while (++i < 100)
	{
		x = (p->hero.position.x + i * cos_hvd) * p->map.w_ratio;
		y = (p->hero.position.y + i * sin_hvd) * p->map.h_ratio;
		if (x > 0 && (int)x < p->mlx.width && y > 0 && (int)y < p->mlx.height)
     		p->mlx.pixels[(int)(x + (int)y * p->mlx.width)] = 0x000000FF;
	}
}

void	render_hero(t_param *p)
{
	int		x;
	int		y;
	double	w_ratio;
	double	h_ratio;
	int		color;

	color = 0x000000FF;
	w_ratio = ((double)p->mlx.width * p->map.zoom) / (double)p->map.width;
	h_ratio = ((double)p->mlx.height * p->map.zoom) / (double)p->map.height;
	p->map.w_ratio = w_ratio;
	p->map.h_ratio = h_ratio;
	render_2d_visible_surface(p, 0x00FF0000);
	render_hero_vector(p);
	x = p->hero.position.x * p->map.w_ratio;
	y = p->hero.position.y * p->map.h_ratio;
	p->mlx.pixels[x + y * p->mlx.width] = color;
	p->mlx.pixels[x + 1 + y * p->mlx.width] = color;
	p->mlx.pixels[x - 1 + y * p->mlx.width] = color;
	p->mlx.pixels[x + (y + 1) * p->mlx.width] = color;
	p->mlx.pixels[x + (y - 1) * p->mlx.width] = color;
}

void     render_2d_map(t_param *p)
{
    int     i;
    int     j;
    int     k;
    int     l;

    i = -1;
    while (++i < p->mlx.height * p->map.zoom)
    {
        j = -1;
        while (++j < p->mlx.width * p->map.zoom)
        {
            k = ((float)i / ((float)p->mlx.height * p->map.zoom)) * (float)p->map.height;
            l = ((float)j / ((float)p->mlx.width * p->map.zoom)) * (float)p->map.width;
			if (p->map.map[(int)(l + k * p->map.width)])
                p->mlx.pixels[j + i * p->mlx.width] = 0x00AAAAAA; 
            else
                p->mlx.pixels[j + i * p->mlx.width] = 0x00FFFFFF;       
        }
    }
	render_hero(p);
}
