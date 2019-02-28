/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_renderer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:37:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 15:54:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_RENDERER
# define MENU_RENDERER

# include "colors/rgb.h"
# include "engine/scene.h"

typedef struct	s_menu_renderer
{
	t_rgb	clear_color;
}				t_menu_renderer;

void			menu_renderer_render(t_scene *scene);

#endif
