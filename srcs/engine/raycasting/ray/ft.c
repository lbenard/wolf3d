/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:13:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/23 19:14:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

t_ray	ft_ray(const float distance, const t_image *texture,
	const float texture_ratio)
{
	t_ray	ret;

	ret.distance = distance;
	ret.texture = texture;
	ret.texture_ratio = texture_ratio;
	return (ret);
}