/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:49:06 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 18:20:27 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"
#include "time.h"

void	print_fps(t_param *p)
{
	static clock_t	last_time = 0;
	char			*fps;
	int				w;
	
	w = p->mlx.width;
	fps = ft_itoa(1.0 / (((double)clock() - last_time) / CLOCKS_PER_SEC));
	last_time = clock();
	mlx_string_put(p->mlx.init, p->mlx.window, w - 90, 10, 0x00FFFFFF, "fps ");
	mlx_string_put(p->mlx.init, p->mlx.window, w - 55, 10, 0x00FFFFFF, fps);
	free(fps);
}

void	reset_image(t_param *p)
{
	int	i;
	int	j;
	t_rgb	sky;
	t_rgb	floor;

	i = -1;
	j = p->mlx.height * 0.5 + 1;
	while (++i <= (int)(0.5 * p->mlx.width * p->mlx.height))
	{
		if (!(i % p->mlx.width))
		{
			j--;
			sky.r = 135.0 * ((double)j / ((double)p->mlx.height * 0.5));
			sky.g = 206.0 * ((double)j / ((double)p->mlx.height * 0.5));
			sky.b = 235.0 * ((double)j / ((double)p->mlx.height * 0.5));
		}
		p->mlx.pixels[i] = ft_rgb_to_int(sky);
	}
	i -= 2;
	j = 0;
	while (++i <= p->mlx.width * p->mlx.height)
	{
		if (!(i % p->mlx.width))
		{
			j++;
			floor.r = 96.0 * ((double)j / ((double)p->mlx.height * 0.5));
			floor.g = 128.0 * ((double)j / ((double)p->mlx.height * 0.5));
			floor.b = 56.0 * ((double)j / ((double)p->mlx.height * 0.5));
		}
		p->mlx.pixels[i] = ft_rgb_to_int(floor);
	}
}

void	draw(t_param *p)
{
	reset_image(p);
	mlx_clear_window(p->mlx.init, p->mlx.window);
	render_3dmap(p);
	render_2d_map(p);
	mlx_put_image_to_window(p->mlx.init, p->mlx.window, p->mlx.img, 0, 0);
	print_fps(p);
}
