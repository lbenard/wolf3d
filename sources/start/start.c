/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:47:39 by pp                #+#    #+#             */
/*   Updated: 2019/03/28 19:22:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/obstacle.h"
#include "libft.h"
#include "mlx.h"

void     check_inputs(t_param *p, int ac, char **av)
{
	if (ac != 2 || (p->map.file_descriptor = open(av[1], O_RDONLY)) <= 2
		|| read(p->map.file_descriptor, NULL, 0) != 0)
        manage_error(p, END, "usage : wolf3d [maps]\n");
}

int	initialize_obstacles(t_param *p)
{
	if (!(p->obstacle = malloc(sizeof(t_obstacle) * W_WIDTH)))
        	return (!manage_error(p, 0, "malloc --> error\n"));
	return (0);
}

int    start(t_param *p, int ac, char **av)
{
    check_inputs(p, ac, av);
    if (initialize_mlx_params(p))
        return (!manage_error(p, 0, "initialize_mlx_params --> error\n"));
    if (initialize_map_params(p))
        return (!manage_error(p, 0, "initialize_map_params --> error\n"));
    if (initialize_hero_params(p))
        return (!manage_error(p, 0, "initialize_hero_params --> error\n"));
    if (initialize_callbacks_params(p))
        return (!manage_error(p, 0, "initialize_callbacks_params --> error\n"));
    if (parse_map(p))
        return (!manage_error(p, 0, "parse_map --> error\n"));
    if (initialize_obstacles(p))
        return (!manage_error(p, 0, "initialize_obstacles --> error\n"));
    return (0);
}