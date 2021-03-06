/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:58:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:52:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/event_handler.h"

t_stack_module_factory	event_handler(void *const object)
{
	static	t_event_handler_args	args;

	args.object = object;
	return (ft_stack_module_factory(ft_stack_module_descriptor(
		init_event_handler, destroy_event_handler), &args));
}
