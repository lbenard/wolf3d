/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:27:22 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:53:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_stack_module_factory	frame(const t_usize size, const t_rgba fill_color)
{
	static t_frame_args		args;

	args.size = size;
	args.fill_color = fill_color;
	return (ft_stack_module_factory(
		ft_stack_module_descriptor(init_frame, destroy_frame),
		&args));
}
