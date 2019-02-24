/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:15:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 16:37:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_list.h"

t_entity_list	*new_entity_list(t_entity *entity)
{
	t_entity_list	*ret;

	if (!(ret = (t_entity_list*)malloc(sizeof(t_entity_list))))
		return (NULL);
	ret->entity = entity;
	init_list_head(&ret->node);
	return (ret);
}

t_entity_list	*entity_list_from_list(t_list_head *list)
{
	return ((t_entity_list*)((t_u8*)list
		- __builtin_offsetof(t_entity_list, node)));
}

t_entity		*entity_from_list(t_list_head *list)
{
	return (entity_list_from_list(list)->entity);
}
