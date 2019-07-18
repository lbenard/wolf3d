/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:02:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/13 00:47:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_TYPE
# define ENTITY_TYPE

# include "engine/entity.h"
# include "engine/scene.h"

typedef enum	s_entity_type
{
	DUMMY_ENTITY_TYPE,
	TEST_ENTITY_TYPE,
	PLAYER_ENTITY_TYPE
}				t_entity_type;

void			entity_type_update(t_entity_node *node, t_scene *scene);
void			free_entity_type(t_entity_node *node);

t_result		get_entities_from_type(t_list_head *const dest,
	const t_list_head *const from, const type_t type);

#endif
