/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2ld_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:11:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:24:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2ld.h"

long double	vec2ld_dot(t_vec2ld a, t_vec2ld b)
{
	return (a.x * b.x
		+ a.y * b.y);
}