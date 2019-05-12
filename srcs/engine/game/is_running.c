/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:08:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 20:08:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_bool	game_is_running(t_game *const self)
{
	return (sfRenderWindow_isOpen(self->window));
}