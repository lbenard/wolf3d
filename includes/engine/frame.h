/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/15 14:47:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include <SFML/Graphics.h>
# include "sizes/usize.h"
# include "sizes/isize.h"
# include "colors/rgba.h"
# include "engine/blend.h"

/*
** Rendering frame with alpha channel
*/
typedef struct	s_frame
{
	const t_usize	size;
	t_u32			*const frame;
	sfRenderTexture	*const render_texture;
	sfSprite		*const sprite;
}				t_frame;

/*
** Constructors
*/
t_result		init_frame(t_frame *const self, const t_usize size,
					t_rgba fill_color);
/*
** Modifiers
*/
void			frame_update(t_frame *const self);
void			frame_clear(t_frame *const self);
void			frame_fill(t_frame *const self, t_rgba fill_color);
void			frame_layer(t_frame *self, t_frame *layer, t_isize pos,
					t_u32 (*blend)(const t_rgba *const back,
						const t_rgba *const front));

/*
** Destructors
*/
void			destroy_frame(t_frame *const self);

#endif