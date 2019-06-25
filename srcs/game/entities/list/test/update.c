/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:08:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/29 19:09:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/test_entity.h"
#include "engine/delta.h"

void	test_entity_update(t_test_entity *self, t_scene *scene)
{
	(void)scene;
	self->data += 1.0f * get_last_delta();
	// printf("%f\n", self->data);
}