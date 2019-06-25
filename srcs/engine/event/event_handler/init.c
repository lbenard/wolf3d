/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:17:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/06/25 17:50:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"
#include "types.h"

t_result	init_event_handler(t_event_handler *self, void *const object)
{
	if (!init_list_head(&self->callbacks))
		return (ERROR);
	*(void**)&self->object = object;
	init_list_head(&self->node);
	init_list_head(&self->childs);
	return (OK);
}