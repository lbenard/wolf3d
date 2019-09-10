/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:11:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:12:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"

t_stack_module_factory	window(const char *const name, const t_usize size)
{
	static t_window_args	args;

	args.name = name;
	args.size = size;
	return (ft_stack_module_factory(ft_stack_module_descriptor(init_window,
		destroy_window), &args));
}