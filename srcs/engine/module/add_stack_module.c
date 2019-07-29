/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_module.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:18:13 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/29 19:44:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"
#include "engine/error.h"

void	module_add_stack_module(t_module *const self,
			t_stack_module_descriptor descriptor,
			void *const module,
			void *const args)
{
	t_stack_module	*stack_module;

	if (!(stack_module = new_stack_module(module, descriptor)))
	{
		self->has_error = TRUE;
		throw_error_str("cannot allocate stack module node");
		return ;
	}
	if (descriptor.init_fn(module, args) == ERROR)
	{
		free_stack_module(stack_module);
		self->has_error = TRUE;
		throw_error_str("failed to init stack module");
		return ;
	}
	list_add_entry(&stack_module->node, &self->stack_modules);
}