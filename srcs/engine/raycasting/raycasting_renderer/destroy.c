/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:20:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 07:41:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/raycasting.h"

void	destroy_raycasting_renderer(t_raycasting_renderer *const self)
{
	destroy_module(&self->module);
	free(self->columns);
}