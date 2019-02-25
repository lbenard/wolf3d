/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:33:43 by pp                #+#    #+#             */
/*   Updated: 2019/02/25 16:59:02 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>


void	render_hero_vector(t_param *p)
{
	float	x;
	float	y;
	float	cos_hvd;
	float	sin_hvd;
	int   i;

	cos_hvd = 0.05f * cos(p->hero.vector_direction);
	sin_hvd = 0.05f * sin(p->hero.vector_direction);
	i = -1;
	while (++i < 100)
	{
		x = ((p->hero.x + i * cos_hvd) * ((float)p->mlx.width * p->map.zoom)) / (float)p->map.width;
		y = ((p->hero.y + i * sin_hvd) * ((float)p->mlx.height * p->map.zoom)) / (float)p->map.height;
        p->mlx.pixels[(int)(x + (int)y * p->mlx.width)] = 0x0000FF00;
	}
}

void	render_hero(t_param *p)
{
	int		x;
	int		y;

	render_hero_vector(p);
	x = (p->hero.x * ((float)p->mlx.width * p->map.zoom)) / (float)p->map.width;
	y = (p->hero.y * ((float)p->mlx.height * p->map.zoom)) / (float)p->map.height;
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