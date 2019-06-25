/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:20:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "engine/entity_node.h"

static void	free_only_entity_node(t_entity_node *node)
{
	free(node);
}

void		free_menu_scene(t_menu_scene *self)
{
	list_foreach(&self->test_entity_list, 0, free_only_entity_node);
	free_scene(&self->super);
	free(self);
}
