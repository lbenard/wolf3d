/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:00:35 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 17:15:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/entity_type.h"
#include "game/entities/dummy_entity.h"

t_dummy_entity	*new_dummy_entity(void)
{
	t_dummy_entity	*ret;

	if (!(ret = (t_dummy_entity*)malloc(sizeof(t_dummy_entity))))
		return (NULL);
	ret->super.type = DUMMY_ENTITY_TYPE;
	ret->super.transform = ft_transform_default();
	return (ret);
}

t_dummy_entity	*dummy_entity_from_entity(t_entity *entity)
{
	return ((t_dummy_entity*)((t_u8*)entity
		- __builtin_offsetof(t_dummy_entity, super)));
}

void			free_dummy_entity(t_dummy_entity *self)
{
	free(self);
}
