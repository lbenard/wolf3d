/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_renderer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:05:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:09:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/raycasting.h"

t_stack_module_factory	raycasting_renderer(const t_usize window_size,
							t_map *const map)
{
	static t_raycasting_renderer_args	args;

	args.window_size = window_size;
	args.map = map;
	return (ft_stack_module_factory(ft_stack_module_descriptor(
		init_raycasting_renderer, destroy_raycasting_renderer), &args));
}