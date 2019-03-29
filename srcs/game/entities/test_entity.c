/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:44:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/03/29 15:23:19 by lbenard          ###   ########.fr       */
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
	if (!init_entity_default(&ret->super, TEST_ENTITY_TYPE))
	{
		free(ret);
		return (NULL);
	}
	ret->data = data;
	return (ret);
}

void			test_entity_update(t_test_entity *self, t_scene *scene)
{
	(void)scene;
	self->data++;
}

void			free_test_entity(t_test_entity *self)
{
	free(self);
}