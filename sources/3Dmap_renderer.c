/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/02/23 22:37:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_column(t_param *p, int i, int j)
{
	float	distance;
	float	x;
	float	y;
	int		k;

	x = p->obstacle.x - p->hero.x;
	y = p->obstacle.y - p->hero.y;
	distance = sqrt(x * x + y * y);
	if (distance < 1.0f)
		distance = 1.0f;
	k = -1;
	while (++k < (int)(((float)p->mlx.height * 0.5) / (float)j))
	{
		p->mlx.pixels[i + (int)(0.5 * p->mlx.height + k) * p->mlx.width] = 0x00FFFFFF;// - 0x00030303 * distance;
		p->mlx.pixels[i + (int)(0.5 * p->mlx.height - k) * p->mlx.width] = 0x00FFFFFF;// - 0x00030303 * distance;
	}
}

#include "libft.h"

void	render_3d_map(t_param *p)
{
	int		i;
	int		j;
	int		k;
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
			x -= p->hero.x;
			y -= p->hero.y;
			distance = sqrt(x * x + y * y);
			if (distance < 1.0f)
				distance = 1.0f;
			k = -1;
			while (++k < (int)(((float)p->mlx.height * 0.5) / distance))
			{
				p->mlx.pixels[j + (int)(0.5 * p->mlx.height + k) * p->mlx.width] = ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
				p->mlx.pixels[j + (int)(0.5 * p->mlx.height - k) * p->mlx.width] = ft_rgb_to_int(ft_hsv_to_rgb(ft_hsv(1 / distance * 360.0, 1.0, 1 / distance)));
			}
		}
	}
	
	
	
	
	// i = -1;
	// p->obstacle.vector_direction = -30.0f;
	// while (++i < p->mlx.width)
	// {
	// 	j = 0;
	// 	p->obstacle.x = p->hero.x;
	// 	p->obstacle.y = p->hero.y;
	// 	p->obstacle.vector_direction += (float)i * (60.0f / (float)p->mlx.width);
	// 	xdirection = cos(p->hero.vector_direction + M_PI / (180.0f / p->obstacle.vector_direction));
	// 	ydirection = sin(p->hero.vector_direction + M_PI / (180.0f / p->obstacle.vector_direction));
	// 	while (p->obstacle.x >= 0 && p->obstacle.x <= p->map.width
	// 		&& p->obstacle.y >= 0 && p->obstacle.y <= p->map.height)
	// 	{
	// 		if (p->map.map[(int)(p->obstacle.x + (int)p->obstacle.y * p->map.width)])
	// 		{
	// 			draw_column(p, i, j);
	// 			break ;
	// 		}
	// 		j++;
	// 		p->obstacle.x = p->hero.x + j * 0.1 * xdirection;
	// 		p->obstacle.y = p->hero.y + j * 0.1 * ydirection;
	// 	}
	// }
}
// void	render_3d_map(t_param *p)
// {
// 	int		i;
// 	//int		j;
// 	int		k;
// 	float	xdirection;
// 	float	ydirection;
// 	float	x = p->hero.x;
// 	float	y = p->hero.y;
// 	float	distance;

// 	i = 0;
// 	p->obstacle.vector_direction = -30.0f;
// 	xdirection = cos(p->hero.vector_direction + M_PI / (180.0f / p->obstacle.vector_direction));
// 	ydirection = sin(p->hero.vector_direction + M_PI / (180.0f / p->obstacle.vector_direction));
// 	while (!p->map.map[(int)(x + (int)y * p->map.width)])
// 	{
// 		i++;
// 		x =  p->hero.x + i * 0.01f * cos(p->hero.vector_direction);
// 		y =  p->hero.y + i * 0.01f * sin(p->hero.vector_direction);
// 	}
// 	x -= p->hero.x;
// 	y -= p->hero.y;
// 	distance = sqrt(x * x + y * y);
// 	if (distance < 1.0f)
// 		distance = 1.0f;
// 	k = -1;
// 	while (++k < (int)(((float)p->mlx.height * 0.5) / distance))
// 	{
// 		p->mlx.pixels[(int)(p->mlx.width * 0.5) + (int)(0.5 * p->mlx.height + k) * p->mlx.width] = 0x00FFFFFF;// - 0x00030303 * distance;
// 		p->mlx.pixels[(int)(p->mlx.width * 0.5) + (int)(0.5 * p->mlx.height - k) * p->mlx.width] = 0x00FFFFFF;// - 0x00030303 * distance;
// 	}
	
	
// 	// i = -1;
// 	// p->obstacle.vector_direction = -30.0f;
// 	// while (++i < p->mlx.width)
// 	// {
// 	// 	j = 0;
// 	// 	p->obstacle.x = p->hero.x;
// 	// 	p->obstacle.y = p->hero.y;
// 	// 	p->obstacle.vector_direction += (float)i * (60.0f / (float)p->mlx.width);
// 	// 	xdirection = cos(p->hero.vector_direction + M_PI / (180.0f / p->obstacle.vector_direction));
// 	// 	ydirection = sin(p->hero.vector_direction + M_PI / (180.0f / p->obstacle.vector_direction));
// 	// 	while (p->obstacle.x >= 0 && p->obstacle.x <= p->map.width
// 	// 		&& p->obstacle.y >= 0 && p->obstacle.y <= p->map.height)
// 	// 	{
// 	// 		if (p->map.map[(int)(p->obstacle.x + (int)p->obstacle.y * p->map.width)])
// 	// 		{
// 	// 			draw_column(p, i, j);
// 	// 			break ;
// 	// 		}
// 	// 		j++;
// 	// 		p->obstacle.x = p->hero.x + j * 0.1 * xdirection;
// 	// 		p->obstacle.y = p->hero.y + j * 0.1 * ydirection;
// 	// 	}
// 	// }
// }