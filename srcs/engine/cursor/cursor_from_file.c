/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_from_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:31:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/22 16:35:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"

t_stack_module_factory	cursor_from_file(const char *const path)
{
	static t_cursor_args	args;

	args.path = path;
	return (ft_stack_module_factory(ft_stack_module_descriptor(
		init_cursor_from_file, destroy_cursor), &args));
}
