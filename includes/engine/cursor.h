/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:38:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:10:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "types.h"
# include "engine/frame.h"

typedef struct	s_cursor
{
	t_bool	is_visible;
	t_bool	is_custom;
	t_frame	custom_cursor;
}				t_cursor;

t_result		init_cursor(t_cursor *const self);
t_result		init_cursor_custom(t_cursor *const self,
					const t_usize cursor_size);
void			cursor_set_visibility(t_cursor *const self,
					const t_bool is_visible);
void			destroy_cursor(t_cursor *const self);

#endif