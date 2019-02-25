/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/25 17:13:53 by lbenard          ###   ########.fr       */
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
void			framebuffer_display(t_framebuffer *self, sfRenderWindow *target);

/*
** Destructors
*/
void			free_framebuffer(t_framebuffer *self);

#endif
