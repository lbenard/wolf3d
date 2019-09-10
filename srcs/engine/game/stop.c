/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:09:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/10 11:55:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"
#include "engine/scene.h"

void	stop_game(void)
{
	destroy_module(&game_singleton()->module);
}