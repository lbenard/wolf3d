/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:15:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/07 16:42:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_node.h"
#include "game/entities/entity_type.h"

#include <stdio.h>

void	free_entity_node(t_entity_node *const node)
{
	printf("freeing entity %p\n", node->entity);
	free_entity_type(node);
	printf("freeing node %p\n", node);
	free(node);
}
