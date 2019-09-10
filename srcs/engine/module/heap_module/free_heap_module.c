/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heap_module.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:54:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/29 20:03:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	free_heap_module(t_heap_module *const module)
{
	module->descriptor.free_fn(*module->module_ref);
	free(module);
}
