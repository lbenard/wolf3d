/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/08/19 15:55:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity_default(t_entity *const self,
				void (*update_fn)())
{
	init_entity(self, ft_transform_default(), update_fn);
	return (OK);
}
