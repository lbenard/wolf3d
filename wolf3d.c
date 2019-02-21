/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:30:44 by pp                #+#    #+#             */
/*   Updated: 2019/02/21 20:11:17 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"


int	check_inputs(t_param *p, int ac, char **av)
{
	if (ac == 2 && (p->map.file_descriptor = open(av[1], O_RDONLY)) > 2
		&& read(p->map.file_descriptor, NULL, 0) == 0)
		return (1);
	else
	{
		ft_putstr("usage : wolf3d [maps]\n");
		return (0);
	}
}

int	initialize_params(t_param *p)
{
	int			t;
	int			x;
	int			y;

    parsing_map(p);
	x = 720;
	y = 480;
	p->mlx.width = x;
	p->mlx.height = y;
	if (!(p->mlx.init = mlx_init()))
		return (!manage_error(p, 0, "mlx_init() --> error\n"));
	if (!(p->mlx.window = mlx_new_window(p->mlx.init, x, y, "Wolf3D")))
		return (!manage_error(p, 1, "mlx_new_window() --> error\n"));
	if (!(p->mlx.img = mlx_new_image(p->mlx.init, x, y)))
		return (!manage_error(p, 2, "mlx_new_image() --> error\n"));
	if (!(p->mlx.pixels = (int*)mlx_get_data_addr(p->mlx.img, &t, &t, &t)))
		return (!manage_error(p, 2, "mlx_get_data() --> error\n"));
	return (0);
}

int	main(int ac, char **av)
{
	t_param p;

	if (check_inputs(&p, ac, av))
	{
		if (initialize_params(&p))
			return (!manage_error(&p, 0, "fill_param() --> error\n"));
		mlx_hook(p.mlx.window, 4, 1L << 2, mouse_callback, (void*)&p);
		mlx_hook(p.mlx.window, 2, 1L << 0, press_callback, (void*)&p);
		mlx_hook(p.mlx.window, 3, 1L << 1, release_callback, (void*)&p);
		mlx_hook(p.mlx.window, 6, 1L << 6, pointer_callback, (void*)&p);
		mlx_loop_hook(p.mlx.init, manage_callback, (void*)&p);
		mlx_loop(p.mlx.init);
	}
	return (0);
}