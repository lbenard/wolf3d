/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:19:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:38:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

void	event_handler_call(t_event_handler *self, sfEvent *event)
{
	t_list_head		*pos;
	t_callback_node	*node;

	pos = self->callbacks.next;
	while (pos != &self->callbacks)
	{
		node = (t_callback_node*)pos;
		if (node->params)
			node->callback(self->object, event, node->params);
		else
			node->callback(self->object, event);
		pos = pos->next;
	}
}