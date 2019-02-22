/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:33:43 by pp                #+#    #+#             */
/*   Updated: 2019/02/22 11:44:54 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void     render_2d_map(t_param *p)
{
    int     i;
    int     j;
    int     k;
    int     l;

    i = -1;
    while (++i < p->mlx.height * 0.2)
    {
        j = -1;
        while (++j < p->mlx.width * 0.2)
        {
            k = ((float)i / ((float)p->mlx.height * 0.2)) * (float)p->map.height;
            l = ((float)j / ((float)p->mlx.width * 0.2)) * (float)p->map.width;
            if (p->map.map[(int)(l + k * p->map.width)])
                p->mlx.pixels[j + i * p->mlx.width] = 0x00FFFFFF;
            else
                p->mlx.pixels[j + i * p->mlx.width] = 0x00AAAAAA;        
        }
            
    }
}