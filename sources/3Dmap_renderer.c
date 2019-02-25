/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/02/25 17:46:10 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

void	render_3d_map(t_param *p)
{
	int     color = 0x00FF0000;
	int		i;
	int		j;
	int		k;
	float	l;
	float	m;
	float	start_direction;
	float	direction;
	float	x = p->hero.x;
	float	y = p->hero.y;
	float	distance;
	float	decalage;

	decalage = (M_PI / 3.0f) / (float)p->mlx.width;
	start_direction = p->hero.vector_direction - M_PI / 6.0f;// = 30 * PI / 180
	j = -1;
	while (++j < p->mlx.width)
	{
		i = 0;
		direction = start_direction + j * decalage;
		while (!p->map.map[(int)(x + (int)y * p->map.width)])
		{
			i++;
			x =  p->hero.x + i * 0.01f * cos(direction);
			y =  p->hero.y + i * 0.01f * sin(direction);
		}
		if (p->map.map[(int)(x + (int)y * p->map.width)])
		{
			//BUG origine zero un rayon sur deux
			l = x * ((float)p->mlx.width * p->map.zoom) / (float)p->map.width;
			m = y * ((float)p->mlx.height * p->map.zoom) / (float)p->map.height;
			l = l > 0 ? l : -l;
			m = m > 0 ? m : -m;
			p->mlx.pixels[(int)l + (int)m * p->mlx.width] = color;
			color++;
			x -= p->hero.x;
			y -= p->hero.y;
			distance = sqrt(x * x + y * y);
			if (distance < 1.0f)
				distance = 1.0f;
			k = -1;
			while (++k < (int)(((float)p->mlx.height * 0.5) / distance))
			{
				if (j > p->mlx.width * p->map.zoom || (int)(0.5 * p->mlx.height - k) > p->mlx.height * p->map.zoom)
				{
					p->mlx.pixels[j + (int)(0.5 * p->mlx.height + k) * p->mlx.width] = ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
					p->mlx.pixels[j + (int)(0.5 * p->mlx.height - k) * p->mlx.width] = ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
				}
			}
		}
	}
}