/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2ld_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:11:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:24:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2ld.h"

t_vec2ld	vec2ld_scalar(t_vec2ld src, long double a)
{
	src.x *= a;
	src.y *= a;
	return (src);
}
