/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:41 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/12 14:51:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

void	search_horizontal_intersection(t_param *p, double x, double y)
{
	int		y_increment;
	double	x_increment;

	y_increment = p->view.sin < 0.0 ? -1 : 1;
	x_increment = (1.0 / p->view.tan) * y_increment;
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)y == (int)p->hero.y)
	{
		x += 0.01 * p->view.cos;
		y += 0.01 * p->view.sin;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
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
		p->view.dist_to_h_wall = sqrt(x * x + y * y);
		p->view.h_hit = 1;
	}
}

void	search_vertical_intersection(t_param *p, double x, double y)
{
	int		x_increment;
	double	y_increment;

	x_increment = p->view.cos < 0.0 ? -1 : 1;
	y_increment = p->view.tan * x_increment;
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)x == (int)p->hero.x)
	{
		x += 0.01 * p->view.cos;
		y += 0.01 * p->view.sin;
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
		p->view.dist_to_v_wall = sqrt(x * x + y * y);
		p->view.v_hit = 1;
	}
}
