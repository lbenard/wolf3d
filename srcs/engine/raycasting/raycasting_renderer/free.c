/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:20:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/12 16:20:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/raycasting.h"

void	free_raycasting_renderer(t_raycasting_renderer *const self)
{
	free(self->columns);
	free(self);
}