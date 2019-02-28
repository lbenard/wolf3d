/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:26:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 15:29:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "engine/type.h"

typedef struct	s_renderer
{
	type_t	type;
}				t_renderer;

t_result		init_renderer(t_renderer *renderer, type_t type);

#endif
