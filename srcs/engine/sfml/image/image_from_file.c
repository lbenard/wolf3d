/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:39:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/07 19:44:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"

t_heap_module_factory	image_from_file(const char *const path)
{
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(void *(*)())sfImage_createFromFile, sfImage_destroy), path));
}