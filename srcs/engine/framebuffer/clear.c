/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:43:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:01:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"
#include "ft/mem.h"

void	frame_clear(t_frame *const self)
{
	ft_bzero(self->frame, sizeof(t_u32) * self->size.x * self->size.y);
}