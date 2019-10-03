/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:26:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:25:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

t_heap_module_factory	raycasting_scene(const t_window *const window)
{
	static t_raycasting_scene_args	args;

	args.window = window;
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(t_new_fn)new_raycasting_scene, free_raycasting_scene), &args));
}
