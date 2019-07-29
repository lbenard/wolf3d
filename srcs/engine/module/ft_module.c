/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_module.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:15:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/29 19:46:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_module	ft_module(void)
{
	t_module	ret;

	init_list_head(&ret.stack_modules);
	init_list_head(&ret.heap_modules);
	ret.has_error = FALSE;
	return (ret);
}