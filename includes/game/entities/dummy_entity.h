/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:01:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 17:06:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_ENTITY
# define DUMMY_ENTITY

# include "engine/entity.h"

typedef struct	s_dummy_entity
{
	t_entity	super;
}				t_dummy_entity;

t_dummy_entity	*new_dummy_entity(void);
t_dummy_entity	*dummy_entity_from_entity(t_entity *entity);
void			free_dummy_entity(t_dummy_entity *self);

#endif
