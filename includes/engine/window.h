/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:40:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:38:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <SFML/Graphics.h>
# include "sizes/usize.h"
# include "types.h"
# include "engine/frame.h"
# include "engine/cursor.h"

typedef struct	s_window
{
	sfRenderWindow	*const window;
	const char		*name;
	t_frame			frame;
	t_cursor		cursor;
	const t_usize	size;
}				t_window;

t_result		init_window(t_window *const self, const char *const name,
					t_usize size);
void			window_update(t_window *const self);
t_bool			window_is_running(const t_window *const self);
t_bool			window_is_focused(const t_window *const self);
t_result		window_set_name(t_window *const self, const char *const name);
void			window_close(t_window *const self);
void			destroy_window(t_window *const self);

#endif