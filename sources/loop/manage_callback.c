/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:58:41 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/17 18:20:43 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"

int		manage_keyboard(t_param *p)
{
	double	x;
	double	y;

	x = 0.0f;
	y = 0.0f;
	if (p->keyboard.key == KEY_ESCAPE)
	{
		end(p, 4);
		exit(0);
	}
	if (p->keyboard.key == KEY_A)
	{
		x = -cos(p->hero.vector_direction + M_PI * 0.5f);
		y = -sin(p->hero.vector_direction + M_PI * 0.5f);
	}
	if (p->keyboard.key == KEY_D)
	{
		x = cos(p->hero.vector_direction + M_PI * 0.5f);
		y = sin(p->hero.vector_direction + M_PI * 0.5f);
	}
	if (p->keyboard.key == KEY_W)
	{
		x = cos(p->hero.vector_direction);
		y = sin(p->hero.vector_direction);
	}
	if (p->keyboard.key == KEY_S)
	{
		x = -cos(p->hero.vector_direction);
		y = -sin(p->hero.vector_direction);
	}
	x *= 0.05;
	y *= 0.05;
	if (!p->map.map[(int)(p->hero.x + x - 0.01 + (int)(p->hero.y + y) * p->map.width)]
		&& !p->map.map[(int)(p->hero.x + x + (int)(p->hero.y + y - 0.01) * p->map.width)]
		&& !p->map.map[(int)(p->hero.x + x + 0.01 + (int)(p->hero.y + y) * p->map.width)]
		&& !p->map.map[(int)(p->hero.x + x + (int)(p->hero.y + y + 0.01) * p->map.width)]
		&& !p->map.map[(int)(p->hero.x + x + (int)(p->hero.y + y) * p->map.width)])
	{
		p->hero.x += x;
		p->hero.y += y;
	}
	if (p->keyboard.key == KEY_LEFT)
		p->hero.angle = ((int)p->hero.angle - 3) % 360;
	if (p->keyboard.key == KEY_RIGHT)
		p->hero.angle = ((int)p->hero.angle + 3) % 360;
	p->hero.vector_direction = p->hero.angle * M_PI / 180.0;
	return (0);
}

int		manage_callback(void *param)
{
	t_param	*p;

	p = (t_param*)param;
	if (p->keyboard.press)
		manage_keyboard(p);
	if (p->keyboard.press)
		draw(p);
	p->mouse.press = 0;
	return (0);
}
