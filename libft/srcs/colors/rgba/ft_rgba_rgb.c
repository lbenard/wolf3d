/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:46:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/04 19:50:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/rgba.h"

t_rgba	ft_rgba_rgb(t_rgb color)
{
	t_rgba	ret;

	ret.r = color.r;
	ret.g = color.g;
	ret.b = color.b;
	ret.a = 255;
	return (ret);
}