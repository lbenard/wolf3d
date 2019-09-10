/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:26:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/03 06:46:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	window_set_name(t_window *const self, const char *const name)
{
	char	*name_dup;

	if (!(name_dup = ft_strdup(name)))
		throw_result_str("Failed while duplicating window's name");
	sfRenderWindow_setTitle(self->window, name_dup);
	self->name = name_dup;
	return (OK);
}