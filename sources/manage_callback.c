/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:58:41 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/12 10:31:01 by pp               ###   ########.fr       */
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
	while (++i <= (int)(0.5 * p->mlx.width * p->mlx.height))
		p->mlx.pixels[i] = 0x004286F4;
	i -= 2;
	while (++i <= p->mlx.width * p->mlx.height)
		p->mlx.pixels[i] = 0x00B241F4;
}

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

void	manage_keyboard(t_param *p)
{
	float	x;
	float	y;

	x = 0.0f;
	y = 0.0f;
	if (p->keyboard.key == KEY_A)
	{
		x = -cos(p->hero.vector_direction + M_PI * 0.5f);
		y = -sin(p->hero.vector_direction + M_PI * 0.5f);
	}
	if (p->keyboard.key == KEY_D)
	{
		x = cos(p->hero.vector_direction + M_PI * 0.5f);
		y = sin(p->hero.vector_direction + M_PI * 0.5f);
	}
	if (p->keyboard.key == KEY_W)
	{
		x = cos(p->hero.vector_direction);
		y = sin(p->hero.vector_direction);	
	}
	if (p->keyboard.key == KEY_S)
	{
		x = -cos(p->hero.vector_direction);
		y = -sin(p->hero.vector_direction);
	}
	if (!p->map.map[(int)(p->hero.x + x  * 0.1f) + (int)(p->hero.y + y * 0.1f) * p->map.width])
	{
		p->hero.x += x * 0.1f;
		p->hero.y += y * 0.1f;
	}
	if (p->keyboard.key == KEY_LEFT)
		p->hero.vector_direction -= 5.0f * M_PI / 180.0f;
	if (p->keyboard.key == KEY_RIGHT)
		p->hero.vector_direction += 5.0f * M_PI / 180.0f;
}

void	draw(t_param *p)
{
	reset_image(p);
	mlx_clear_window(p->mlx.init, p->mlx.window);
	render_2d_map(p);
	render_3d_map(p);
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
	if (p->keyboard.press)
		manage_keyboard(p);
	if (p->keyboard.press)
		draw(p);
	p->mouse.press = 0;
	return (0);
}
