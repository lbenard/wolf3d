/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_stack_module.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:48:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/08/31 18:29:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

void	module_remove_stack_module(t_module *const self,
			const void *const module_ref)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_stack_module	*module;

	pos = &self->stack_modules;
	next = pos->next;
	while ((pos = next) != &self->stack_modules)
	{
		next = next->next;
		module = (t_stack_module*)pos;
		if (module->module_ref == module_ref)
		{
			list_del_entry(pos);
			free_stack_module(module);
			break ;
		}
	}
}