/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:27:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 07:40:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"

void	destroy_module(t_module *const self)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_stack_module	*stack_module;
	t_heap_module	*heap_module;

	pos = &self->stack_modules;
	next = pos->next;
	while ((pos = next) != &self->stack_modules)
	{
		next = next->next;
		stack_module = (t_stack_module*)pos;
		stack_module->descriptor.destroy_fn(stack_module->module_ref);
		free(stack_module);
	}
	pos = &self->heap_modules;
	next = pos->next;
	while ((pos = next) != &self->heap_modules)
	{
		next = next->next;
		heap_module = (t_heap_module*)pos;
		heap_module->descriptor.free_fn(*heap_module->module_ref);
		free(heap_module);
	}
}