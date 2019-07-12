/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:29:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/09 17:02:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"

void	free_frame(t_frame *const self)
{
	free(self->frame);
	sfRenderTexture_destroy(self->render_texture);
	sfSprite_destroy(self->sprite);
}
