/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:29 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:41:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity(t_entity *const entity, const type_t type,
	const t_transform transform)
{
	*(type_t*)&entity->type = type;
	entity->transform = transform;
	return (OK);
}