/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:08:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:08:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/test_entity.h"
#include "game/entities/entity_type.h"

t_test_entity	*new_test_entity(void)
{
	t_test_entity	*ret;

	if (!(ret = (t_test_entity*)malloc(sizeof(t_test_entity))))
		return (NULL);
	if (!init_entity_default(&ret->super, TEST_ENTITY_TYPE))
	{
		free(ret);
		return (NULL);
	}
	ret->data = 0.0f;
	return (ret);
}