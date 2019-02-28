/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:02:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 16:10:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_TYPE
# define ENTITY_TYPE

# include "engine/entity.h"
# include "engine/scene.h"

typedef enum	s_entity_type
{
	DUMMY_ENTITY_TYPE,
	TEST_ENTITY_TYPE
}				t_entity_type;

void			entity_type_update(t_entity *entity, t_scene *scene);
void			free_entity_type(t_entity *entity);

#endif
