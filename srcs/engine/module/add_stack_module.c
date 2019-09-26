/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_module.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:18:13 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/26 19:13:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	module_add_stack_module(t_module *const self,
			const t_stack_module_factory factory,
			void *const module)
{
	t_stack_module	*stack_module;

	if (self->has_error == TRUE)
		return ;
	if (!(stack_module = new_stack_module(module, factory.descriptor)))
	{
		self->has_error = TRUE;
		throw_error_str("module_add_stack_module()",
			"cannot allocate stack module node");
		return ;
	}
	if (factory.descriptor.init_fn(module, factory.args) == ERROR)
	{
		free(stack_module);
		self->has_error = TRUE;
		throw_error_str("module_add_stack_module()",
			"failed to init stack module");
		return ;
	}
	list_add_entry(&stack_module->node, &self->stack_modules);
}