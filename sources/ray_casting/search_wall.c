/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:17:43 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 18:18:15 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

void	search_horizontal_wall(t_param *p, double x, double y)
{
	int		y_increment;
	double	x_increment;

	y_increment = p->ray.sin < 0.0 ? -1 : 1;
	x_increment = (y_increment / p->ray.tan);
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)y == (int)p->hero.y)
	{
		x += 0.01 * p->ray.cos;
		y += 0.01 * p->ray.sin;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x - 0.01 + (int)y * p->map.width)])
		 	x -= 0.01;
		if (p->map.map[(int)(x + (int)(y - 0.01) * p->map.width)])
		 	y -= 0.01;
		if (p->map.map[(int)(x + 0.01 + (int)y * p->map.width)])
		 	x += 0.01;
		if (p->map.map[(int)(x + (int)(y + 0.01) * p->map.width)])
		 	y += 0.01;
		if (p->map.map[(int)(x + (int)y * p->map.width)])
		 	break ;
		x += x_increment;
		y += y_increment;
	}
	p->horizontal_wall.x = x;
	p->horizontal_wall.y = y;
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		p->ray.dist_to_h_wall = sqrt(x * x + y * y);
		p->ray.h_hit = 1;
	}
}

void	search_vertical_wall(t_param *p, double x, double y)
{
	int		x_increment;
	double	y_increment;

	x_increment = p->ray.cos < 0.0 ? -1 : 1;
	y_increment = p->ray.tan * x_increment;
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)x == (int)p->hero.x)
	{
		x += 0.01 * p->ray.cos;
		y += 0.01 * p->ray.sin;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x + (int)y * p->map.width)])
		 	break ;
		x += x_increment;
		y += y_increment;
	}
	p->vertical_wall.x = x;
	p->vertical_wall.y = y;
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		p->ray.dist_to_v_wall = sqrt(x * x + y * y);
		p->ray.v_hit = 1;
	}
}
