/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsv_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 00:12:07 by pp                #+#    #+#             */
/*   Updated: 2019/02/03 00:12:09 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_hsv_to_rgb(t_hsv color)
{
	int		i;
	float	f;
	float	p;
	float	q;
	float	t;

	if (color.s == 0.0f)
		return (ft_rgb(color.v, color.v, color.v));
	color.h = (color.h == 360) ? 0 : color.h / 60.0f;
	i = (int)color.h;
	f = color.h - i;
	p = color.v * (1.0f - color.s) * 255;
	q = color.v * (1.0f - (color.s * f)) * 255;
	t = color.v * (1.0f - (color.s * (1.0 - f))) * 255;
	if (i == 0)
		return (ft_rgb(color.v * 255, t, p));
	else if (i == 1)
		return (ft_rgb(q, color.v * 255, p));
	else if (i == 2)
		return (ft_rgb(p, color.v * 255, t));
	else if (i == 3)
		return (ft_rgb(p, q, color.v * 255));
	else if (i == 4)
		return (ft_rgb(t, p, color.v * 255));
	return (ft_rgb(color.v * 255, p, q));
}