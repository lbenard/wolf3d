/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_rendererbis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:09:01 by pp                #+#    #+#             */
/*   Updated: 2019/03/07 14:22:13 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    initialize_view(t_param *p)
{
    p->view.position.x = p->hero.x;
    p->view.position.y = p->hero.y;
    p->view.direction.x = -1;
    p->view.direction.y = 0;
    p->view.plane.x = 0;
    p->view.plane.y = 0.66;
}

void    render_3d_map(t_param *p)
{
    int     column;
    float   x;

    column = -1;
    initialize_view(p);
    while (++column < p->mlx.width)
    {
        x = 2 * column / (double)p->mlx.width - 1;
        p->view.rayon.x = p->view.direction.x + p->view.plane.x * x;
        p->view.rayon.y = p->view.direction.y + p->view.plane.y * x; 
    }
}