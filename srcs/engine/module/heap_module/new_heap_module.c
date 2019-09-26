/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_heap_module.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:49:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/26 19:13:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

t_heap_module	*new_heap_module(void **const module,
					t_heap_module_descriptor descriptor)
{
	t_heap_module	*ret;

	if (!(ret = (t_heap_module*)malloc(sizeof(t_heap_module))))
		return (throw_error_str("new_heap_module()",
			"failed to allocate new heap module node"));
	init_list_head(&ret->node);
	ret->module_ref = module;
	ret->descriptor = descriptor;
	return (ret);
}