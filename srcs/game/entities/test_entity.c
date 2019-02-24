/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:44:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 17:28:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/test_entity.h"
#include "game/entities/entity_type.h"

t_test_entity	*new_test_entity(int data)
{
	t_test_entity	*ret;

	if (!(ret = (t_test_entity*)malloc(sizeof(t_test_entity))))
		return (NULL);
	ret->super.type = TEST_ENTITY_TYPE;
	ret->super.transform = ft_transform_default();
	ret->data = data;
	return (ret);
}

t_test_entity	*test_entity_from_entity(t_entity *entity)
{
	return ((t_test_entity*)((t_u8*)entity
		- __builtin_offsetof(t_test_entity, super)));
}

void			free_test_entity(t_test_entity *self)
{
	free(self);
}
