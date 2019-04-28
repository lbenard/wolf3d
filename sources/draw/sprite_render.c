/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/04/15 19:40:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/obstacle.h"
#include "../includes/rayon.h"
#include "../includes/bitmap.h"
#include "libft.h"

double	to_last_int(double n)
{
	return (n - (double)((int)n));
}

double	to_next_int(double n)
{
	return (1.0 - to_last_int(n));
}

t_pos2d	pos2d_soustraction(t_pos2d p1, t_pos2d p2)
{
	t_pos2d res;
	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	return (res);
}
t_pos2d	pos2d_addition(t_pos2d p1, t_pos2d p2)
{
	t_pos2d res;
	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	return (res);
}

t_pos2d	initialize_rays(t_ray *h, t_ray *v, t_angle direction, t_pos2d hero)
{
	v->shift.x = (direction.cos < 0) ? -1 : 0;
	v->shift.y = 0;
	v->direction = direction.cos < 0 ? 'O' : 'E';
	v->position.x = (direction.cos >= 0)
		? to_next_int(hero.x) : -to_last_int(hero.x);
	v->position.y = v->position.x * direction.tan;
	v->position = pos2d_addition(hero, v->position);
	v->increment.x = (direction.cos < 0.0)? -1.0 : 1.0;
	v->increment.y = v->increment.x * direction.tan;
	v->hit = 0;
	h->shift.x = 0;
	h->shift.y = (direction.sin < 0) ? -1 : 0;
	h->direction = direction.sin < 0 ? 'N' : 'S';
	h->position.y = (direction.sin >= 0)
	       ? to_next_int(hero.y) : -to_last_int(hero.y);
	h->position.x = h->position.y / direction.tan;
	h->position = pos2d_addition(hero, h->position);
	h->increment.y = (direction.sin < 0.0)? -1.0 : 1.0;
	h->increment.x = h->increment.y / direction.tan;
	h->hit = 0;
}

t_pos2d	limit_ray(t_pos2d ray, double x_max, double y_max)
{
	if (ray.x < 0)
		ray.x = 0;
	if (ray.y < 0)
		ray.y = 0;
	if (ray.x > x_max)
		ray.x = x_max;
	if (ray.y > y_max)
		ray.y = y_max;
	return (ray);
}	      

int	ray_is_in_map(t_map map, t_pos2d ray)
{
	if (ray.x <= 0 || ray.y <= 0)
		return (0);
	if (ray.x >= map.width || ray.y >= map.height)
		return (0);
	return (1);
}

int	is_there_a_wall(t_map map, t_pos2d ray, t_pos2d shift)
{
	ray = pos2d_addition(ray, shift);
	if (map.map[(int)ray.x + (int)ray.y * map.width] != 0)
		return (1);
	return (0);
}

double	distance(t_pos2d p1, t_pos2d p2)
{
	double x;
	double y;

	x = p1.x - p2.x;
	y = p1.y - p2.y;
	return (sqrt(x * x + y * y));
}

t_obstacle create_obstacle(t_ray rayon)
{
	t_obstacle obstacle;

	obstacle.position = rayon.position;
	obstacle.distance = rayon.distance;
	obstacle.type = rayon.hit? WALL : LIMIT;
	obstacle.direction = rayon.direction;
	if (rayon.distance > 1)
		obstacle.size = (double)W_HEIGHT / rayon.distance;
	else
		obstacle.size = W_HEIGHT;
	obstacle.next = NULL;
	return (obstacle);
}

t_pos2d	ray_increment(t_map map, t_pos2d ray, t_pos2d inc)
{
	t_pos2d res;
	
	res = pos2d_addition(ray, inc);
	if (ray_is_in_map(map, res))
		return (res);
	return (limit_ray(res, map.width, map.height));
}

t_obstacle find_obstacle(t_map map, t_entity hero, t_angle direction,
	double fisheye_correction)
{
	t_ray	h;
	t_ray	v;

	initialize_rays(&h, &v, direction, hero.position);
	while (!h.hit && ray_is_in_map(map, h.position))
	{
		if ((h.hit = is_there_a_wall(map, h.position, h.shift)))
			break;
		h.position = ray_increment(map, h.position, h.increment);
	}
	while (!v.hit && ray_is_in_map(map, v.position))
	{
		if ((v.hit = is_there_a_wall(map, v.position, v.shift)))
			break;
		v.position = ray_increment(map, v.position, v.increment);
	}
	h.distance = fisheye_correction * distance(h.position, hero.position);
	v.distance = fisheye_correction * distance(v.position, hero.position);
	if (h.distance < v.distance)
		return (create_obstacle(h));
	else
		return (create_obstacle(v));
}

t_angle	new_angle(double radian)
{
	t_angle angle;

	angle.rad = radian;
	angle.cos = cos(radian);
	angle.sin = sin(radian);
	angle.tan = tan(radian);
	return (angle);
}
	
void	render_sprites(t_param *p, t_sprite *sprites, t_obstacle *obstacle)
{
	int	column_number;
	double	shift;
	t_angle	direction;
	double	fisheye_correction;

	shift = (M_PI / 3.0f) / (double)p->mlx.width;
	direction = new_angle(p->hero.vector_direction - (M_PI / 6.0f));
	fisheye_correction = -M_PI / 6.0;
	column_number = -1;
	while (++column_number < p->mlx.width)
	{
		p->obstacle[column_number] = find_obstacle(p->map
			, p->hero, direction, cos(fisheye_correction));
		direction = new_angle(direction.rad + shift);
		fisheye_correction += shift;
	}
	draw_3dmap(p, p->obstacle);
}
