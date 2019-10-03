/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:51:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"

t_stack_module_factory	entity_list(void)
{
	return (ft_stack_module_factory(ft_stack_module_descriptor(
		init_entity_list, destroy_entity_list), NULL));
}
