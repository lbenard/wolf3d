/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:43:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:43:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/framebuffer.h"
#include "ft/mem.h"

void	framebuffer_clear(t_framebuffer *const self)
{
	ft_bzero(self->framebuffer, sizeof(t_u32) * self->size.x * self->size.y);
}