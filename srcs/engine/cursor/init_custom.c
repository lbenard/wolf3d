/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_custom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:47:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/15 14:45:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/cursor.h"
#include "engine/error.h"

t_result	init_cursor_custom(t_cursor *const self, const t_usize cursor_size)
{
	init_cursor(self);
	if (init_frame(&self->custom_cursor, cursor_size, ft_rgba(255, 0, 0, 255))
		== ERROR)
		return (throw_result_str("Error while creating cursor's frame"));
	self->is_custom = TRUE;
	return (OK);
}