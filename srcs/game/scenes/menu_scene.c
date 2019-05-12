/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/08 14:31:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/entity_node.h"
#include "game/entities/entity_type.h"
#include "ft/str.h"

t_menu_scene	*new_menu_scene(void)
{
	t_menu_scene	*ret;

	if (!(ret = (t_menu_scene*)malloc(sizeof(t_menu_scene))))
		return (NULL);
	if (!init_scene(&ret->super, MENU_SCENE_TYPE, "Main menu"))
	{
		free(ret);
		return (NULL);
	}
	// ret->background_color = ft_rgb(127, 255, 0);
	init_list_head(&ret->test_entity_list);
	return (ret);
}

void			menu_scene_update(t_menu_scene *self, float delta)
{
	(void)delta;
	get_entities_from_type(&self->test_entity_list, &self->super.entities,
		TEST_ENTITY_TYPE);
	list_foreach(&self->test_entity_list,
		__builtin_offsetof(t_entity_node, node), entity_type_update);
}

#include <stdio.h>

void			menu_scene_render(t_menu_scene *self, t_framebuffer *fb)
{
	size_t	x;
	size_t	y;
	t_u32	color;

	// printf("entity count: %lu\n", list_size(&self->test_entity_list));
	color = hsv_to_int(ft_hsv((float)(10 * list_size(&self->test_entity_list) % 360), 1.0f, 1.0f));
	y = 0;
	while (y < fb->size.y)
	{
		x = 0;
		while (x < fb->size.x)
		{
			fb->framebuffer[fb->size.x * y + x] = color;
			x++;
		}
		y++;
	}
}

static void		free_only_entity_node(t_entity_node *node)
{
	free(node);
}

void			free_menu_scene(t_menu_scene *self)
{
	list_foreach(&self->test_entity_list, 0, free_only_entity_node);
	free_scene(&self->super);
	free(self);
}
