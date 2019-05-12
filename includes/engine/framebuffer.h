/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/04/20 01:25:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMEBUFFER_H
# define FRAMEBUFFER_H

# include <SFML/Graphics.h>
# include "libft.h"

/*
** Rendering framebuffer with alpha channel
*/
typedef struct	s_framebuffer
{
	const t_usize	size;
	t_u32			*const framebuffer;
	sfRenderTexture	*const render_texture;
	sfSprite		*const sprite;
}				t_framebuffer;

/*
** Constructors
*/
t_result		init_framebuffer(t_framebuffer *const self, const t_usize size);
/*
** Modifiers
*/
void			framebuffer_update(t_framebuffer *const self);
void			framebuffer_clear(t_framebuffer *const self);
void			framebuffer_display(t_framebuffer *const self,
	sfRenderWindow *const target);

/*
** Destructors
*/
void			free_framebuffer(t_framebuffer *const self);

#endif
