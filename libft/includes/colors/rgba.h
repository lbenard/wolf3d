/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:15:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/11 23:19:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBA_H
# define RGBA_H

# include "types.h"
# include "colors/hsv.h"
# include "colors/rgb.h"

/*
** RGBA color
*/
typedef struct	s_rgba
{
	t_u8	a;
	t_u8	b;
	t_u8	g;
	t_u8	r;
}				t_rgba;

/*
** Constructors
*/
t_rgba			ft_rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
t_rgba			ft_rgba_rgb(t_rgb color);
t_rgba			ft_rgba_int(t_u32 color);
t_rgba			ft_rgba_hsv(t_hsv color);

/*
** Casts
*/
t_u32			rgba_to_int(t_rgba color);

#endif
