/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:04:22 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:34:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/error.h"

t_result	init_game(t_game *const self, const char *const name,
	const t_usize window_size)
{
	if (init_window(&self->window, name, window_size) == ERROR)
		return (throw_result_str("Error while creating sfWindow"));
	if (init_event_handler(&self->event_handler, self) == ERROR)
	{
		destroy_window(&self->window);
		return (throw_result_str("Error while creating event handler"));
	}
	self->scene = NULL;
	return (OK);
}