/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_module_factory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:11:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 18:12:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_heap_module_factory	ft_heap_module_factory(
							const t_heap_module_descriptor descriptor,
							const void *args)
{
	t_heap_module_factory	factory;

	factory.descriptor = descriptor;
	factory.args = args;
	return (factory);
}