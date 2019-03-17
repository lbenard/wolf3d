/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:47:39 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 17:42:34 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"


void     check_inputs(t_param *p, int ac, char **av)
{
	if (ac != 2 || (p->map.file_descriptor = open(av[1], O_RDONLY)) <= 2
		|| read(p->map.file_descriptor, NULL, 0) != 0)
        manage_error(p, END, "usage : wolf3d [maps]\n");
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
    return (0);
}