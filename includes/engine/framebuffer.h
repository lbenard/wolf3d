/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 18:05:52 by lbenard          ###   ########.fr       */
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
	t_usize		size;
	t_u32		*framebuffer;
	sfImage		*image;
	sfTexture	*texture;
	sfSprite	*sprite;
}				t_framebuffer;

/*
** Constructors
*/
t_result		init_framebuffer(t_framebuffer *self, t_usize size);

/*
** Modifiers
*/
void			framebuffer_update(t_framebuffer *self);
void			framebuffer_clear(t_framebuffer *self);
/*
** Destructors
*/
void			free_framebuffer(t_framebuffer *self);

#endif
