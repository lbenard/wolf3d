/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:50:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/22 18:02:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/image_entity.h"
#include "engine/error.h"

t_image_entity	*new_image_entity_from_file(
					const t_image_entity_args *const args)
{
	t_image_entity	*ret;

	if (!(ret = (t_image_entity*)malloc(sizeof(t_image_entity))))
		return (throw_error_str("failed while allocating new image entity"));
	init_entity_default(&ret->super, image_entity_update);
	module_add_stack_module(&ret->super.module, frame_from_file(args->path),
		&ret->image);
	if (ret->super.module.has_error)
	{
		free_image_entity(ret);
		return (throw_error_str("failed while creating new image entity"));
	}
	return (ret);
}