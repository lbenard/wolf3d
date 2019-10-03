/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_module_descriptor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:59:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:07:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_stack_module_descriptor	ft_stack_module_descriptor(t_result (*init_fn)(),
								void (*destroy_fn)())
{
	t_stack_module_descriptor	descriptor;

	descriptor.init_fn = init_fn;
	descriptor.destroy_fn = destroy_fn;
	return (descriptor);
}