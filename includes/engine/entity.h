/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:17:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/04/16 18:29:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "maths/transform.h"
# include "containers/list.h"
# include "engine/type.h"

typedef struct	s_entity
{
	const type_t	type;
	t_transform		transform;
}				t_entity;

t_result	init_entity(t_entity *const entity, const type_t type,
	const t_transform transform);
t_result	init_entity_default(t_entity *const entity, const type_t type);

#endif
