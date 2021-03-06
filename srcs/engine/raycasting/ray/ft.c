/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:13:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 22:27:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

t_ray	ft_ray(const t_vec2f player_position,
			const t_vec2f hit_position,
			const t_image *texture,
			const float texture_ratio)
{
	t_ray	ret;

	ret.distance = vec2f_distance(player_position, hit_position);
	ret.hit_position = hit_position;
	ret.texture = texture;
	ret.texture_ratio = texture_ratio;
	return (ret);
}
