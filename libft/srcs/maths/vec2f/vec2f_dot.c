/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 01:00:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/22 14:53:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2f.h"

float	vec2f_dot(t_vec2f a, t_vec2f b)
{
	return (a.x * b.x + a.y * b.y);
}