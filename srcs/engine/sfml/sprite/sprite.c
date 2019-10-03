/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:00:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:16:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sprite.h"

t_heap_module_factory	sprite(void)
{
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(t_new_fn)sfSprite_create, sfSprite_destroy), NULL));
}
