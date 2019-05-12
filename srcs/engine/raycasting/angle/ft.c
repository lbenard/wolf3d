/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:04:32 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 15:11:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycasting.h"

t_angle	ft_angle(float rad)
{
	t_angle	ret;
	
	ret.cos = cos(rad);
	ret.sin = sin(rad);
	ret.tan = tan(rad);
	ret.rad = rad;
	return (ret);
}