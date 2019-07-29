/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_heap_module.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:44:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/29 20:05:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"
#include "engine/error.h"

void	module_add_heap_module(t_module *const self,
			t_heap_module_descriptor descriptor,
			void **const module,
			void *const args)
{
	t_heap_module	*heap_module;

	if (!(heap_module = new_heap_module(module, descriptor)))
	{
		self->has_error = TRUE;
		throw_error_str("cannot allocate heap module node");
		return ;
	}
	if (!(*module = descriptor.new_fn(args)))
	{
		free_heap_module(heap_module);
		self->has_error = TRUE;
		throw_error_str("failed to init heap module");
		return ;
	}
	list_add_entry(&heap_module->node, &self->heap_modules);
}