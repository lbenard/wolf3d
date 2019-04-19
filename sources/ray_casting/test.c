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
	if (x < 0 || x >= p->map.width)
		return (0);
	if (y < 0 || y >= p->map.height)
		return (0);
	return (1);
}

static int	check_walls(t_param *p, double x, double y)
{
	if (p->map.map[(int)(x + (int)y * p->map.width)])
	 	return (1);
	return (0);
}

void	search_horizontal_wall(t_param *p, double x, double y)
{
	double	x_increment;
	int	y_increment;
	double	x_miss;
	double	y_miss;
	int	direction;

	direction = p->ray.sin < 0 ? -1 : 0;
	y_miss = -(y - ((double)(int)y));
	if (!(p->ray.sin < 0))
		y_miss += 1.0;
	x_miss = y_miss / p->ray.tan;
	y += y_miss;
	x += x_miss;
	y_increment = p->ray.sin < 0.0 ? -1 : 1;
	x_increment = (y_increment / p->ray.tan);
	while (check_map_limits(p, x, y))
	{	
		if (check_walls(p, x, y + direction))
			break;
		x += x_increment;
		y += y_increment;
	}
	/*if (y < 0)
		y = 0;
	if (x > p->map.width)
		x = p->map.width;*/
	if (x < 0)
		x = 0;
	if (y > p->map.height)
		y = p->map.height;
//	printf("h x %lf, y %lf  ", x, y);
	p->horizontal_wall.x = x;
	p->horizontal_wall.y = y;
	if (check_map_limits(p, x, y) && check_walls(p, x, y + direction))
		p->ray.h_hit = 1;
	x -= p->hero.x;
	y -= p->hero.y;
	p->ray.dist_to_h_wall = sqrt(x * x + y * y);
}

void	search_vertical_wall(t_param *p, double x, double y)
{
	int	x_increment;
	double	y_increment;
	double	x_miss;
	double	y_miss;
	int	direction;

	direction = p->ray.cos < 0 ? -1 : 0;
	x_miss = -(x - ((double)(int)x));
	if (!(p->ray.cos < 0))
		x_miss += 1.0;
	y_miss = x_miss * p->ray.tan;
	x += x_miss;
	y += y_miss;
	x_increment = p->ray.cos < 0.0 ? -1 : 1;
	y_increment = p->ray.tan * x_increment;
	while (check_map_limits(p, x, y))
	{
		if (check_walls(p, x + direction, y))
			break;
		x += x_increment;
		y += y_increment;
	}
	/*if (y < 0)
		y = 0;
	if (x > p->map.width)
		x = p->map.width;*/
	if (y > p->map.height)
		y = p->map.height;
	if (x < 0)
		x = 0;
//	printf("v x %lf, y %lf\n", x, y);
	p->vertical_wall.x = x;
	p->vertical_wall.y = y;
	if (check_map_limits(p, x, y) && check_walls(p, x + direction, y))
		p->ray.v_hit = 1;
	x -= p->hero.x;
	y -= p->hero.y;
	p->ray.dist_to_v_wall = sqrt(x * x + y * y);
}
