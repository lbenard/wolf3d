/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:44:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 18:12:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_H
# define MODULE_H

# include "types.h"
# include "containers/list.h"

/*
** A generic-type module initializer and destructor that keep track of allocated
** sub-modules and potential malloc errors.
*/

typedef void				*(*t_new_fn)();

typedef struct				s_stack_module_descriptor
{
	t_result	(*init_fn)();
	void		(*destroy_fn)();
}							t_stack_module_descriptor;

t_stack_module_descriptor	ft_stack_module_descriptor(t_result (*init_fn)(),
								void (*destroy_fn)());

typedef struct				s_stack_module_factory
{
	t_stack_module_descriptor	descriptor;
	const void					*args;
}							t_stack_module_factory;

t_stack_module_factory		ft_stack_module_factory(
								const t_stack_module_descriptor descriptor,
								const void *args);

typedef struct				s_stack_module
{
	t_list_head					node;
	void						*module_ref;
	t_stack_module_descriptor	descriptor;
}							t_stack_module;

t_stack_module				*new_stack_module(void *const module,
								t_stack_module_descriptor descriptor);
void						free_stack_module(t_stack_module *const module);

typedef struct				s_heap_module_descriptor
{
	void	*(*new_fn)();
	void	(*free_fn)();
}							t_heap_module_descriptor;

t_heap_module_descriptor	ft_heap_module_descriptor(void *(*new_fn)(),
								void (*free_fn)());

typedef struct				s_heap_module_factory
{
	t_heap_module_descriptor	descriptor;
	const void					*args;
}							t_heap_module_factory;

t_heap_module_factory		ft_heap_module_factory(
								const t_heap_module_descriptor descriptor,
								const void *args);

typedef struct				s_heap_module
{
	t_list_head					node;
	void						**module_ref;
	t_heap_module_descriptor	descriptor;
}							t_heap_module;

t_heap_module				*new_heap_module(void **const module,
								t_heap_module_descriptor descriptor);
void						free_heap_module(t_heap_module *const module);

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
