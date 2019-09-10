/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:04:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 12:30:52 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_stack_module_factory	frame_from_file(const char *const path)
{
	static t_frame_args		args;

	args.path = path;
	return ft_stack_module_factory(ft_stack_module_descriptor(
		init_frame_from_file, destroy_frame), &args);
}