/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:56:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/26 18:36:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity(t_entity *entity, type_t type, t_transform transform)
{
	entity->type = type;
	entity->transform = transform;
	return (OK);
}

t_result	init_entity_default(t_entity *entity, type_t type)
{
	entity->type = type;
	entity->transform = ft_transform_default();
	return (OK);
}
