/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:19:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/15 21:25:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/menu_scene.h"
#include "game/scenes/scene_type.h"
#include "engine/frame.h"
#include "engine/blend.h"
#include "ft/mem.h"

void	menu_scene_render(t_menu_scene *self, t_frame *fb)
{
	frame_clear(fb);
	(void)self;
}