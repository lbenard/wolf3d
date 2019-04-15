/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hero_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:12:50 by ppetitea          #+#    #+#             */
/*   Updated: 2019/04/15 19:28:48 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_walls(t_param *p, double move_x, double move_y)
{
	int		i;
	double	x;
	double	y;

	move_x *= 0.1;
	move_y *= 0.1;
	i = 0;
	while (++i < 15)
	{
		x = i * move_x;
		y = i * move_y;
	if (p->map.map[(int)(p->hero.x + x - 0.01 + (int)(p->hero.y + y) * p->map.width)]
		|| p->map.map[(int)(p->hero.x + x + (int)(p->hero.y + y - 0.01) * p->map.width)]
		|| p->map.map[(int)(p->hero.x + x + 0.01 + (int)(p->hero.y + y) * p->map.width)]
		|| p->map.map[(int)(p->hero.x + x + (int)(p->hero.y + y + 0.01) * p->map.width)]
		|| p->map.map[(int)(p->hero.x + x + (int)(p->hero.y + y) * p->map.width)])
			return (0);
	}
	return (1);
}

int		check_map_limits(t_param *p, double move_x, double move_y)
{
	if (p->hero.x + move_x < 0
		|| p->hero.x + move_x > p->map.width)
		return (0);
	if (p->hero.y + move_y < 0
		|| p->hero.y + move_y > p->map.height)
		return (0);
	return (1);
}

void	find_hero_vector(t_param *p, t_dpoint_2d *hv, int sign, double shift)
{
	hv->x = sign * cos(p->hero.vector_direction + shift);
	hv->y = sign * sin(p->hero.vector_direction + shift);
}

void	manage_hero_moves(t_param *p)
{
	t_dpoint_2d hero_vector;

	hero_vector.x = 0.0;
	hero_vector.y = 0.0;
	if (p->keyboard.key == KEY_A)
		find_hero_vector(p, &hero_vector, -1, M_PI * 0.5);
	else if (p->keyboard.key == KEY_D)
		find_hero_vector(p, &hero_vector, 1, M_PI * 0.5);
	else if (p->keyboard.key == KEY_W)
		find_hero_vector(p, &hero_vector, 1, 0);
	else if (p->keyboard.key == KEY_S)
		find_hero_vector(p, &hero_vector, -1, 0);
	hero_vector.x *= 0.2;
	hero_vector.y *= 0.2;
	if (check_walls(p, hero_vector.x, hero_vector.y)
	&& check_map_limits(p, hero_vector.x, hero_vector.y))
	{
		p->hero.x += hero_vector.x;
		p->hero.y += hero_vector.y;
	}
}