/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:15:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:56:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_result	init_module(t_module *const self)
{
	init_list_head(&self->stack_modules);
	init_list_head(&self->heap_modules);
	self->has_error = FALSE;
	return (OK);
}
