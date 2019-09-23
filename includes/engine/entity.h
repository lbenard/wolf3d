/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:17:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/14 13:31:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "engine/module.h"
# include "maths/transform.h"
# include "engine/type.h"

typedef			void *(*t_new_fn)();

typedef struct	s_entity
{
	t_module		module;
	t_transform		transform;
	void			(*update_fn)();
}				t_entity;

t_result	init_entity(t_entity *const self,
				const t_transform transform,
				void (*update_fn)());
t_result	init_entity_default(t_entity *const self,
				void (*update_fn)());

#endif
