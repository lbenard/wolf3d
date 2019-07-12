/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:53:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/12 23:52:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLER_H
# define EVENT_HANDLER_H

# include "containers/list.h"
# include <SFML/Window.h>

/*
** Callbacks list for each event handler
*/
typedef struct	s_callback_node
{
	t_list_head	node;
	void		(*callback)();
	void		*params;
}				t_callback_node;

/*
** Constructors
*/
t_callback_node	*new_callback_node(void (*callback)(), void *params);
void			free_callback_node(t_callback_node *self);

typedef struct	s_event_handler
{
	t_list_head				node;
	t_list_head				childs;
	void					*const object;
	t_list_head				callbacks;
}				t_event_handler;

t_result		init_event_handler(t_event_handler *const self,
	void *const object);
t_result		event_handler_add_callback(t_event_handler *const self,
	t_callback_node *const callback);
void			event_handler_add_sub_handler(t_event_handler *const self,
	t_event_handler *const sub_handler);
void			event_handler_call(t_event_handler *self, sfEvent *event);
void			destroy_event_handler(t_event_handler *const self);

#endif