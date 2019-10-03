/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:52:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:16:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_texture.h"

t_heap_module_factory	render_texture(const t_usize size)
{
	static t_render_texture_args	args;

	args.size = size;
	return (ft_heap_module_factory(ft_heap_module_descriptor(
		(t_new_fn)new_render_texture, free_render_texture), &args));
}
