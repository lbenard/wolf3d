/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:23:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/08/31 15:24:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/game.h"

t_stack_module_descriptor	game_descriptor(void)
{
	return (ft_stack_module_descriptor(start_game, stop_game));
}