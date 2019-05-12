/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:05:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/08 17:09:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <SFML/Graphics.h>
# include "maths/vec3f.h"

typedef struct	s_sprite
{
	sfImage	*texture;
	t_vec3f	position;
	float	size;
}				t_sprite;

#endif