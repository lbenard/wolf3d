/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:53:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/05/03 19:16:42 by lbenard          ###   ########.fr       */
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
	void					*const object;
	t_list_head				callbacks;
	struct s_event_handler	*sub_handler;
}				t_event_handler;

t_result		init_event_handler(t_event_handler *const self,
	void *const object);
t_result		event_handler_add_callback(t_event_handler *const self,
	t_callback_node *const callback);
void			event_handler_call(t_event_handler *self, sfEvent *event);
void			free_event_handler(t_event_handler *const self);

#endif