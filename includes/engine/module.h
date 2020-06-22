/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:44:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:25:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_H
# define MODULE_H

# include "types.h"
# include "containers/list.h"

typedef void				*(*t_new_fn)();

/*
** Init and destroy functions for stack modules
*/
typedef struct				s_stack_module_descriptor
{
	t_result	(*init_fn)();
	void		(*destroy_fn)();
}							t_stack_module_descriptor;

t_stack_module_descriptor	ft_stack_module_descriptor(t_result (*init_fn)(),
								void (*destroy_fn)());

/*
** Stack factory, stores the argument used to build a stack module node
*/
typedef struct				s_stack_module_factory
{
	t_stack_module_descriptor	descriptor;
	const void					*args;
}							t_stack_module_factory;

t_stack_module_factory		ft_stack_module_factory(
								const t_stack_module_descriptor descriptor,
								const void *args);

/*
** Stack module node
*/
typedef struct				s_stack_module
{
	t_list_head					node;
	void						*module_ref;
	t_stack_module_descriptor	descriptor;
}							t_stack_module;

t_stack_module				*new_stack_module(void *const module,
								t_stack_module_descriptor descriptor);
void						free_stack_module(t_stack_module *const module);

/*
** New and free functions for heap modules
*/
typedef struct				s_heap_module_descriptor
{
	void	*(*new_fn)();
	void	(*free_fn)();
}							t_heap_module_descriptor;

t_heap_module_descriptor	ft_heap_module_descriptor(void *(*new_fn)(),
								void (*free_fn)());

/*
** Heap factory, stores the argument used to build a heap module node
*/
typedef struct				s_heap_module_factory
{
	t_heap_module_descriptor	descriptor;
	const void					*args;
}							t_heap_module_factory;

t_heap_module_factory		ft_heap_module_factory(
								const t_heap_module_descriptor descriptor,
								const void *args);

/*
** Heap module node
*/
typedef struct				s_heap_module
{
	t_list_head					node;
	void						**module_ref;
	t_heap_module_descriptor	descriptor;
}							t_heap_module;

t_heap_module				*new_heap_module(void **const module,
								t_heap_module_descriptor descriptor);
void						free_heap_module(t_heap_module *const module);

/*
** A generic-type module initializer and destructor that keeps track of
** allocated sub-modules and potential malloc errors. Modules are kept in
** lists, stack (scope dependant) modules and heap (non-scope dependant, like
** list nodes) modules. Every module is initialized with a factory which just
** stores how to build the module (init_* or new_* function) and how to destroy
** it (destroy_* or free_* function). Whenever a module catches an error, it
** stops building newver modules and set `has_error` to TRUE.
*/
typedef struct				s_module
{
	t_list_head	stack_modules;
	t_list_head	heap_modules;
	t_bool		has_error;
}							t_module;

t_result					init_module(t_module *self);

void						module_add_stack_module(t_module *const self,
								const t_stack_module_factory factory,
								void *const module);
void						module_remove_stack_module(t_module *const self,
								const void *const module_ref);

void						module_add_heap_module(t_module *const self,
								const t_heap_module_factory factory,
								void **const module);
void						module_remove_heap_module(t_module *const self,
								void **const module_ref);

void						destroy_module(t_module *const self);

#endif
