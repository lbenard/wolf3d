/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_in_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 07:06:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/02 07:07:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

t_bool	is_ray_in_map(const t_vec2f pos, const t_map *const map)
{
	if (pos.x <= 0 || pos.y <= 0)
		return (FALSE);
	else if (pos.x >= map->size.x || pos.y >= map->size.y)
		return (FALSE);
	return (TRUE);
}