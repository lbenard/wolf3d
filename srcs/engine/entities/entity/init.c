/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:29 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:51:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity(t_entity *const self,
				const t_transform transform,
				void (*update_fn)())
{
	init_module(&self->module);
	self->transform = transform;
	self->update_fn = update_fn;
	return (OK);
}
