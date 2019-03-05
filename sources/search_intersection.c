/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:41 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/05 19:43:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

int		sign(void *number, char type)
{
	if (type == 'i')
		return (*(int*)number >= 0 ? 1 : -1);
	if (type == 'f')
		return (*(float*)number >= 0.0f ? 1 : -1);
	if (type == 'd')
		return (*(double*)number >= 0.0 ? 1 : -1);
	return (0);
}

float	search_horizontal_intersection(t_param *p, float cosx, float siny, float direction)
{
	float	x;
	float	y;
	float	tx;
	int		signy;

	x = p->hero.x;
	y = p->hero.y;
	signy = sign(&siny, 'f');
	tx = 1.0 / tan(direction);
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)y == (int)p->hero.y)
	{
		x += 0.01 * cosx;
		y += 0.01 * siny;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x + (int)y * p->map.width)])
			break ;
		x += tx * signy;
		y += signy;
	}
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
		render_2d_visible_surface(p, x, y, 0x00FF0000);
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		return (sqrt(x * x + y * y));
	}
	return (-42);
}

float	search_vertical_intersection(t_param *p, float cosx, float siny, float direction)
{
	float	x;
	float	y;
	float	ty;
	int		signx;

	x = p->hero.x;
	y = p->hero.y;
	signx = sign(&cosx, 'f');
	ty = tan(direction);
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& (int)x == (int)p->hero.x)
	{
		x += 0.01 * cosx;
		y += 0.01 * siny;
	}
	while (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
	{
		if (p->map.map[(int)(x + (int)y * p->map.width)])
			break ;
		x += signx;
		y += ty * signx;
	}
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height)
		render_2d_visible_surface(p, x, y, 0x000000FF);
	if (x > 0 && (int)x < p->map.width && y > 0 && (int)y < p->map.height
		&& p->map.map[(int)(x + (int)y * p->map.width)])
	{
		x -= p->hero.x;
		y -= p->hero.y;
		return (sqrt(x * x + y * y));
	}
	return (-42);
}
