/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_heap_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:27:50 by lbenard           #+#    #+#             */
/*   Updated: 2019/08/31 18:30:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

void	module_remove_heap_module(t_module *const self,
			void **const module_ref)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_heap_module	*module;

	pos = &self->heap_modules;
	next = pos->next;
	while ((pos = next) != &self->heap_modules)
	{
		next = next->next;
		module = (t_heap_module*)pos;
		if (module->module_ref == module_ref)
		{
			list_del_entry(pos);
			free_heap_module(module);
			break ;
		}
	}
}