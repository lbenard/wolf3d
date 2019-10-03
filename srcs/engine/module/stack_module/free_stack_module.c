/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_module.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:50:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 18:15:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	free_stack_module(t_stack_module *const module)
{
	module->descriptor.destroy_fn(module->module_ref);
	free(module);
}
