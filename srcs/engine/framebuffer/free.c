/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:29:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:44:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/framebuffer.h"

void		free_framebuffer(t_framebuffer *const self)
{
	free(self->framebuffer);
	sfRenderTexture_destroy(self->render_texture);
	sfSprite_destroy(self->sprite);
}
