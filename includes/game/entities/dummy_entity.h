/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:01:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/03/29 15:15:34 by lbenard          ###   ########.fr       */
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
void			free_dummy_entity(t_dummy_entity *self);

#endif
