/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_module_descriptor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:00:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 18:14:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_heap_module_descriptor	ft_heap_module_descriptor(void *(*new_fn)(),
								void (*free_fn)())
{
	t_heap_module_descriptor	descriptor;

	descriptor.new_fn = new_fn;
	descriptor.free_fn = free_fn;
	return (descriptor);
}
