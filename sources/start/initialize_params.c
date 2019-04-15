/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:07:22 by pp                #+#    #+#             */
/*   Updated: 2019/04/15 19:39:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"

int     initialize_mlx_params(t_param *p)
{
    int     w;
    int     h;
    int     t;

	p->mlx.width = 1080;
	p->mlx.height = 720;
	w = p->mlx.width;
	h = p->mlx.height;
    if (!(p->mlx.init = mlx_init()))
		return (!manage_error(p, 0, "mlx_init() --> error\n"));
	if (!(p->mlx.window = mlx_new_window(p->mlx.init, w, h, "Wolf3D")))
		return (!manage_error(p, 1, "mlx_new_window() --> error\n"));
	if (!(p->mlx.img = mlx_new_image(p->mlx.init, w, h)))
		return (!manage_error(p, 2, "mlx_new_image() --> error\n"));
	if (!(p->mlx.pixels = (int*)mlx_get_data_addr(p->mlx.img, &t, &t, &t)))
		return (!manage_error(p, 2, "mlx_get_data() --> error\n"));
    return (0);
}

int     initialize_map_params(t_param *p)
{
    char    *line;

    p->map.zoom = 0.2;
    get_next_line(p->map.file_descriptor, &line);
    p->map.width = ft_atoi(line);
    get_next_line(p->map.file_descriptor, &line);
    p->map.height = ft_atoi(line);
    if (!(p->map.map = malloc(sizeof(int) * p->map.width * p->map.height)))
        return (!manage_error(p, 0, "malloc map --> error\n"));
	if (!(p->map.rays = malloc(sizeof(t_dpoint_2d) * p->mlx.width)))
		return (!manage_error(p, 3, "malloc rays --> error\n"));
	if (!(p->map.texture = bitmap_parser("textures/rivet_steel_2.bmp")))
		return (!manage_error(p, 3, "parse texture --> error\n"));
    return (0);
}

int     initialize_hero_params(t_param *p)
{
    p->hero.vector_direction = 0;
	p->hero.angle = 0;
	p->hero.x = 5.0;
	p->hero.y = 5.0;
    return (0);
}

int     initialize_callbacks_params(t_param *p)
{
	p->keyboard.key = -42;
    return (0);
}