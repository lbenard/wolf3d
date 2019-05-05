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
	double	rad;

	if (p->keyboard.key == KEY_LEFT)
		rad = -3.0 * (M_PI / 180.0);
	if (p->keyboard.key == KEY_RIGHT)
		rad = 3.0 * (M_PI / 180.0);
	p->hero.view.direction += rad;
}
