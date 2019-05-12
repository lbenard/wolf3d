/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:41:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity_default(t_entity *const entity, const type_t type)
{
	*(type_t*)&entity->type = type;
	entity->transform = ft_transform_default();
	return (OK);
}
