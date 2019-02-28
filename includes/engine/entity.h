/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:17:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/26 18:35:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "maths/transform.h"
# include "containers/list.h"
# include "engine/type.h"

typedef struct	s_entity
{
	type_t		type;
	t_transform	transform;
}				t_entity;

t_result	init_entity(t_entity *entity, type_t type, t_transform transform);
t_result	init_entity_default(t_entity *entity, type_t type);

#endif
