/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_entity_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:48:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/22 18:02:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/image_entity.h"

t_heap_module_factory	image_entity_from_file(const char *const path)
{
	static t_image_entity_args	args;

	args.path = path;
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(t_new_fn)new_image_entity_from_file, free_image_entity), &args));
}