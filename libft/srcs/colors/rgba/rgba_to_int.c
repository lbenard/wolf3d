/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:47:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/11 23:17:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/rgba.h"

t_u32	rgba_to_int(t_rgba color)
{
	t_u32	result;

	result = color.a;
	result <<= 8;
	result += color.b;
	result <<= 8;
	result += color.g;
	result <<= 8;
	result += color.r;
	return (result);
}