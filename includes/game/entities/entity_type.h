/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:02:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/25 17:53:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_TYPE
# define ENTITY_TYPE

# include "engine/entity.h"

typedef enum	s_entity_type
{
	DUMMY_ENTITY_TYPE,
	TEST_ENTITY_TYPE
}				t_entity_type;

void			free_entity_type(t_entity *entity);

#endif
