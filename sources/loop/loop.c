/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:03:20 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 17:03:42 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "mlx.h"

void    loop(t_param *p)
{
    mlx_hook(p->mlx.window, 4, 1L << 2, mouse_callback, (void*)p);
    mlx_hook(p->mlx.window, 2, 1L << 0, press_callback, (void*)p);
    mlx_hook(p->mlx.window, 3, 1L << 1, release_callback, (void*)p);
    mlx_hook(p->mlx.window, 6, 1L << 6, pointer_callback, (void*)p);
    mlx_loop_hook(p->mlx.init, manage_callback, (void*)p);
    mlx_loop(p->mlx.init);
}
