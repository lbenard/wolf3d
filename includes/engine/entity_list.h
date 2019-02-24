/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 16:37:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_LIST
# define ENTITY_LIST

# include "engine/entity.h"
# include "containers/list.h"

typedef struct	s_entity_list
{
	t_entity	*entity;
	t_list_head	node;
}				t_entity_list;

t_entity_list	*new_entity_list(t_entity *entity);
t_entity_list	*entity_list_from_list(t_list_head *list);
t_entity		*entity_from_list(t_list_head *list);

#endif
