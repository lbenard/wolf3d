/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:27:51 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:36:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/window.h"

void	destroy_window(t_window *const self)
{
	sfRenderWindow_destroy(self->window);
	free(*(char**)&self->name);
	destroy_frame(&self->frame);
	destroy_cursor(&self->cursor);
}