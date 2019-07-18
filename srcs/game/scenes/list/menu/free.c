/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:24:07 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/17 13:04:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "engine/entity_node.h"

// static void	free_only_entity_node(t_entity_node *node)
// {
// 	free(node);
// }

void		free_menu_scene(t_menu_scene *self)
{
	(void)self;
	// destroy_scene(&self->super);
	free(self);
}
