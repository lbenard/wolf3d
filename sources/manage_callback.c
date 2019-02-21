/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:58:41 by ppetitea          #+#    #+#             */
/*   Updated: 2019/02/21 17:59:00 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"
#include "time.h"

void	reset_image(t_param *p)
{
	int	i;

	i = -1;
	while (++i <= p->mlx.width * p->mlx.height)
		p->mlx.pixels[i] = 0;
}

void	print_fps(t_param *p)
{
	static clock_t	last_time = 0;
	char			*fps;
	int				w;
	
	w = p->mlx.width;
	fps = ft_itoa(1.0 / (((double)clock() - last_time) / CLOCKS_PER_SEC));
	last_time = clock();
	mlx_string_put(p->mlx.init, p->mlx.window, w - 75, 30, 0x00FFFFFF, "fps ");
	mlx_string_put(p->mlx.init, p->mlx.window, w - 40, 30, 0x00FFFFFF, fps);
	free(fps);
}

void	draw(t_param *p)
{
	reset_image(p);
	mlx_clear_window(p->mlx.init, p->mlx.window);


	mlx_put_image_to_window(p->mlx.init, p->mlx.window, p->mlx.img, 0, 0);
	print_fps(p);
}

int		manage_callback(void *param)
{
	t_param	*p;

	p = (t_param*)param;
	if (p->keyboard.key == KEY_ESCAPE)
	{
		manage_error(p, 4, "Exit with ESC\n");
		exit(0);
	}
	p->mouse.press = 0;
	draw(p);
	return (0);
}
