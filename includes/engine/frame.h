/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:00:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include <SFML/Graphics.h>
# include "libft.h"

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
t_result		init_frame(t_frame *const self, const t_usize size);
/*
** Modifiers
*/
void			frame_update(t_frame *const self);
void			frame_clear(t_frame *const self);
void			frame_display(t_frame *const self,
	sfRenderWindow *const target);
void			frame_layer(t_frame *const self,
	const t_frame *const layer, const t_usize position);

/*
** Destructors
*/
void			free_frame(t_frame *const self);

#endif
