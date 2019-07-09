/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:39:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/01 20:48:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/framebuffer.h"

void	framebuffer_layer(t_framebuffer *const self,
	const t_framebuffer *const layer, const t_usize position)
{
	t_usize	size;

	size.x = ft_min(position.x + layer->size.x)
}