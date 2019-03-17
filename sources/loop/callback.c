/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:22:30 by pp                #+#    #+#             */
/*   Updated: 2019/02/21 17:11:07 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "mlx.h"

int		press_callback(int key, void *param)
{
	t_param *p;

	p = (t_param*)param;
	p->keyboard.press = 1;
	p->keyboard.key = key;
	return (1);
}

int		release_callback(int key, void *param)
{
	t_param *p;

	(void)key;
	p = (t_param*)param;
	p->keyboard.press = 0;
	return (1);
}

int		pointer_callback(int x, int y, void *param)
{
	t_param *p;

	p = (t_param*)param;
	x -= p->mlx.width * 0.5;
	y -= p->mlx.height * 0.5;
	p->pointeur.x = (double)x / ((double)p->mlx.width * 0.5);
	p->pointeur.y = (double)y / ((double)p->mlx.height * 0.5);
	if (x >= 0 && x <= p->mlx.width  && y >= 0 && y <= p->mlx.height)
		p->pointeur.inside = 1;
	else
		p->pointeur.inside = 0;
	return (1);
}

int		mouse_callback(int button, int x, int y, void *param)
{
	t_param *p;

	p = (t_param*)param;
	if (x >= 0 && x <= p->mlx.width && y >= 0 && y <= p->mlx.height)
	{
		p->mouse.button = button;
		p->mouse.x = x;
		p->mouse.y = y;
		p->mouse.press = 1;
	}
	return (1);
}