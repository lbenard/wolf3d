/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:14:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:09:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_LIST_H
# define ENTITY_LIST_H

# include "engine/module.h"
# include "engine/entity.h"
# include "containers/list.h"

/*
** Entity batch used in scenes
*/
typedef struct			s_entity_list
{
	t_module	module;
	t_list_head	list;
}						t_entity_list;

typedef struct			s_entity_list_args
{
	char	dummy;
}						t_entity_list_args;

t_stack_module_factory	entity_list(void);

t_result				init_entity_list(t_entity_list *const self,
							const t_entity_list_args *const args);

t_entity				*entity_list_add_entity(t_entity_list *const self,
							const t_heap_module_factory factory);
void					entity_list_update(t_entity_list *const self);

void					destroy_entity_list(t_entity_list *const self);

#endif
