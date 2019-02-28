/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:48:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 17:48:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"

void	set_last_delta(float delta)
{
	*get_delta_ptr() = delta;
}

float	get_last_delta(void)
{
	return (*get_delta_ptr());
}

float	*get_delta_ptr(void)
{
	static float	delta = 0.0f;
	return (&delta);
}
