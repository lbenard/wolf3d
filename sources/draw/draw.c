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

	i = -1;
	while (++i <= (int)(0.5 * p->mlx.width * p->mlx.height))
		p->mlx.pixels[i] = 0x004286F4;
	i -= 2;
	while (++i <= p->mlx.width * p->mlx.height)
		p->mlx.pixels[i] = 0x00B241F4;
}

void	draw(t_param *p)
{
	reset_image(p);
	mlx_clear_window(p->mlx.init, p->mlx.window);
	render_3d_map(p);
	render_2d_map(p);
	mlx_put_image_to_window(p->mlx.init, p->mlx.window, p->mlx.img, 0, 0);
	print_fps(p);
}