/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_entity.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:42:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 17:25:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ENTITY
# define TEST_ENTITY

# include "engine/entity.h"
# include "engine/entity_list.h"
# include "engine/scene.h"

typedef struct	s_test_entity
{
	int			data;
	t_entity	super;
}				t_test_entity;

t_test_entity	*new_test_entity(int data);
t_test_entity	*test_entity_from_entity(t_entity *entity);
void			test_entity_update(t_test_entity *self, t_scene *scene);
void			free_test_entity(t_test_entity *self);

#endif
