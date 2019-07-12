/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:44:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:01:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

void	frame_display(t_frame *const self,
	t_window *const target)
{
	sfRenderWindow_drawSprite(target->window, self->sprite, NULL);
	sfRenderWindow_display(target->window);
}