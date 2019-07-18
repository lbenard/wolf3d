/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:55:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/15 13:58:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"
#include "game/scenes/scene_type.h"

void	free_raycasting_scene(t_raycasting_scene *self)
{
	destroy_scene(&self->super);
	destroy_map(&self->map);
	destroy_raycasting_renderer(&self->renderer);
	free(self);
}