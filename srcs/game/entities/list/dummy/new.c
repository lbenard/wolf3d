/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:02:17 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:02:26 by lbenard          ###   ########.fr       */
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
	if (!init_entity_default(&ret->super, DUMMY_ENTITY_TYPE))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}