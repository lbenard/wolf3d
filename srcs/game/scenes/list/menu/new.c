/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/15 21:25:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/entity_node.h"
#include "engine/error.h"

t_menu_scene	*new_menu_scene(const t_window *const window)
{
	t_menu_scene	*ret;

	if (!(ret = (t_menu_scene*)malloc(sizeof(t_menu_scene))))
		return (NULL);
	if (!init_scene(&ret->super, MENU_SCENE_TYPE, "Main menu"))
	{
		free(ret);
		return (NULL);
	}
	(void)window;
	return (ret);
}