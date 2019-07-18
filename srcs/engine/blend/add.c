/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:49:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/18 14:43:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/blend.h"

t_u32	blend_add(const t_rgba *const back, const t_rgba *const front)
{
	// a->r = 255;
	// a->g = 255;
	// a->b = 255;
	// a->r = (255 - b->a) * a->r + b->r * (b->a / 255.0f);
	// a->g = (255 - b->a) * a->g + b->g * (b->a / 255.0f);
	// a->b = (255 - b->a) * a->b + b->b * (b->a / 255.0f);
	// a->a = 255;
	// return (rgba_to_int(ft_rgba((255 - front->a) * back->r + front->r * (front->a / 255.0f),
	// 	(255 - front->a) * back->g + front->g * (front->a / 255.0f),
	// 	(255 - front->a) * back->b + front->b * (front->a / 255.0f), 255)));
	(void)back;
	(void)front;
	return (rgba_to_int(ft_rgba(255, 255, 255, 255)));
}