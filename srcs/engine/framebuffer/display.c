/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:44:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:44:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/framebuffer.h"

void	framebuffer_display(t_framebuffer *const self,
	sfRenderWindow *const target)
{
	sfRenderWindow_drawSprite(target, self->sprite, NULL);
	sfRenderWindow_display(target);
}