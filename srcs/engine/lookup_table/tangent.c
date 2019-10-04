/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:07:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:04:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "engine/lookup_table.h"
#include "types.h"

static void	generate(float *const array, float max_amplitude, size_t steps)
{
	double	step;
	size_t	i;

	step = max_amplitude / steps;
	i = 0;
	while (i < steps)
	{
		array[i] = tan(step * i);
		i++;
	}
}

float		tangent_lookup(const float t)
{
	static t_bool	is_generated = FALSE;
	static float	array[TANGENT_TABLE_SIZE];

	if (!is_generated)
	{
		generate(array, 2 * M_PI, TANGENT_TABLE_SIZE);
		is_generated = TRUE;
	}
	return (array[(int)lerp(0, TANGENT_TABLE_SIZE - 1, t)]);
}
