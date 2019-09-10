/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:21:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/06 14:25:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"

t_heap_module_factory	menu_scene(const t_window *const window)
{
	static t_menu_scene_args	args;

	args.window = window;
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(void *(*)())new_menu_scene, free_menu_scene), &args));
}