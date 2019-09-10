/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack_module.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:47:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/31 15:09:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

t_stack_module	*new_stack_module(void *const module,
					t_stack_module_descriptor descriptor)
{
	t_stack_module	*ret;

	if (!(ret = (t_stack_module*)malloc(sizeof(t_stack_module))))
		return (throw_error_str("Failed to allocate new stack module node"));
	init_list_head(&ret->node);
	ret->module_ref = module;
	ret->descriptor = descriptor;
	return (ret);
}