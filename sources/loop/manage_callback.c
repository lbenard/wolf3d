/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:58:41 by ppetitea          #+#    #+#             */
/*   Updated: 2019/04/15 19:29:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"

void	manage_keyboard(t_param *p)
{
	if (p->keyboard.key == KEY_A || p->keyboard.key == KEY_D
		|| p->keyboard.key == KEY_W || p->keyboard.key == KEY_S)
		manage_hero_moves(p);
	else if (p->keyboard.key == KEY_LEFT || p->keyboard.key == KEY_RIGHT)
		manage_hero_vector_direction(p);
	else if (p->keyboard.key == KEY_ESCAPE)
	{
		end(p, 4);
		exit(0);
	}
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
