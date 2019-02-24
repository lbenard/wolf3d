/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:05:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/24 17:38:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "containers/list.h"

typedef struct	s_scene
{
	char			*name;
	t_list_head		entities;
	// t_renderer		renderer;
	// t_input_manager	input_manager;
}				t_scene;

#endif
