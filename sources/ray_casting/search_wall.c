/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:17:43 by pp                #+#    #+#             */
/*   Updated: 2019/03/29 16:37:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

static int	check_map_limits(t_param *p, double x, double y)
{
	if (x < 0 || x > p->map.width)
		return (0);
	if (y < 0 || y > p->map.height)
		return (0);
	return (1);
}

static int	check_walls(t_param *p, double *x, double *y)
{
	if (p->map.map[(int)(*x - 0.005 + (int)*y * p->map.width)])
	 	*x -= 0.005;
	if (p->map.map[(int)(*x + (int)(*y - 0.005) * p->map.width)])
	 	*y -= 0.005;
	if (p->map.map[(int)(*x + 0.005 + (int)*y * p->map.width)])
	 	*x += 0.005;
	if (p->map.map[(int)(*x + (int)(*y + 0.005) * p->map.width)])
	 	*y += 0.005;
	if (p->map.map[(int)(*x + (int)*y * p->map.width)])
	 	return (1);
	return (0);
}

void	search_horizontal_wall(t_param *p, double x, double y)
{
	int	y_increment;
	double	x_increment;

	while (check_map_limits(p, x, y) && (int)y == (int)p->hero.y)
	{
		x += 0.005 * p->ray.cos;
		y += 0.005 * p->ray.sin;
	}
	y_increment = p->ray.sin < 0.0 ? -1 : 1;
	x_increment = (y_increment / p->ray.tan);
	while (check_map_limits(p, x, y))
	{	
		if (check_walls(p, &x, &y))
			break;
		x += x_increment;
		y += y_increment;
	}
	p->horizontal_wall.x = x;
	p->horizontal_wall.y = y;
	if (check_map_limits(p, x, y)
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

	while (check_map_limits(p, x, y) && (int)x == (int)p->hero.x)
	{
		x += 0.005 * p->ray.cos;
		y += 0.005 * p->ray.sin;
	}
	x_increment = p->ray.cos < 0.0 ? -1 : 1;
	y_increment = p->ray.tan * x_increment;
	while (check_map_limits(p, x, y))
	{
		if (check_walls(p, &x, &y))
			break;
		x += x_increment;
		y += y_increment;
	}
	p->vertical_wall.x = x;
	p->vertical_wall.y = y;
	if (check_map_limits(p, x, y)
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		p->ray.dist_to_v_wall = sqrt(x * x + y * y);
		p->ray.v_hit = 1;
	}
}
