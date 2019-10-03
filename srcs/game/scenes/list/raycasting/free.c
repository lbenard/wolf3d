/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:55:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:19:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"

void	free_raycasting_scene(t_raycasting_scene *self)
{
	destroy_scene(&self->super);
	free(self);
}
