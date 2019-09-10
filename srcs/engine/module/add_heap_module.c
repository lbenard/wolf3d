/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_heap_module.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:44:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/07 20:02:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"
#include "engine/error.h"

void	module_add_heap_module(t_module *const self,
			const t_heap_module_factory factory,
			void **const module)
{
	t_heap_module	*heap_module;

	if (self->has_error == TRUE)
		return ;
	if (!(heap_module = new_heap_module(module, factory.descriptor)))
	{
		self->has_error = TRUE;
		throw_error_str("cannot allocate heap module node");
		return ;
	}
	if (factory.args)
		*module = factory.descriptor.new_fn(factory.args);
	else
		*module = factory.descriptor.new_fn();
	if (!(*module))
	{
		free_heap_module(heap_module);
		self->has_error = TRUE;
		throw_error_str("failed to init heap module");
		return ;
	}
	list_add_entry(&heap_module->node, &self->heap_modules);
}