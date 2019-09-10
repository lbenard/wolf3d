/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:38:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 13:31:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "engine/module.h"
# include "types.h"
# include "engine/frame.h"

typedef struct			s_cursor
{
	t_module	module;
	t_bool		is_visible;
	t_frame		cursor;
}						t_cursor;

typedef struct			s_cursor_args
{
	t_usize	size;
	t_rgba	fill_color;
}						t_cursor_args;

t_stack_module_factory	cursor(const t_usize size, const t_rgba fill_color);

t_result				init_cursor(t_cursor *const self,
							t_cursor_args *args);
void					cursor_set_visibility(t_cursor *const self,
							const t_bool is_visible);
void					destroy_cursor(t_cursor *const self);

#endif