/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:13:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/28 15:36:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"
#include <math.h>

static float			euclidean_distance(const t_vec2f a, const t_vec2f b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

t_ray	ft_ray(const t_vec2f player_position, const t_vec2f hit_position,
	const t_image *texture,	const float texture_ratio)
{
	t_ray	ret;

	ret.distance = euclidean_distance(player_position, hit_position);
	ret.hit_position = hit_position;
	ret.texture = texture;
	ret.texture_ratio = texture_ratio;
	return (ret);
}