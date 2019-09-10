/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:04:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:05:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_stack_module_factory	map(const char *const path)
{
	static t_map_args	args;

	args.path = path;
	return (ft_stack_module_factory(ft_stack_module_descriptor(init_map,
		destroy_map), &args));
}