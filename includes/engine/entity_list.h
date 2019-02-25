/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/25 17:54:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_LIST
# define ENTITY_LIST

# include "engine/entity.h"
# include "containers/list.h"

/*
** Entity list used in scenes
*/
typedef struct	s_entity_list
{
	t_entity	*entity;
	t_list_head	node;
}				t_entity_list;

/*
** Constructors
*/
t_entity_list	*new_entity_list(t_entity *entity);

/*
** Casts
*/
t_entity_list	*entity_list_from_list(t_list_head *list);
t_entity		*entity_from_list(t_list_head *list);

/*
** Destructors
*/
void			free_entity_list(t_entity_list *list);

#endif
