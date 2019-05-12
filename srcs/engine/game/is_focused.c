/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_focused.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:09:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 20:09:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_bool	game_is_focused(t_game *const self)
{
	return (sfRenderWindow_hasFocus(self->window));
}