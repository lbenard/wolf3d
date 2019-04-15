/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hero_vector_direction.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:17:20 by ppetitea          #+#    #+#             */
/*   Updated: 2019/04/15 19:36:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	manage_hero_vector_direction(t_param *p)
{
	if (p->keyboard.key == KEY_LEFT)
		p->hero.angle = ((int)p->hero.angle - 3) % 360;
	if (p->keyboard.key == KEY_RIGHT)
		p->hero.angle = ((int)p->hero.angle + 3) % 360;
	p->hero.vector_direction = p->hero.angle * M_PI / 180.0;
}