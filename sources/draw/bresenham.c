/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:09:13 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/07 12:49:04 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	bresenham_dz(t_param *param, t_point *p, int color)
{
	int	e;
	int	dx;
	int	dz;
	int	xs;
	int	zs;

	e = ft_abs(p[1].z - p[0].z);
	dz = 2 * e;
	dx = 2 * ft_abs(p[1].x - p[0].x);
	xs = p[1].x > p[0].x ? 1 : -1;
	zs = p[1].z > p[0].z ? 1 : -1;
	while (p->z != p[1].z + zs && p->z >= 0 && p->z <= param->mlx.height)
	{
		if (p->x > 0 && p->x < param->mlx.width
			&& p->z > 0 && p->z < param->mlx.height)
			param->mlx.pixels[p->x + p->z * param->mlx.width] = color;
		e -= dx;
		if (e < 0)
		{
			p->x += xs;
			e += dz;
		}
		p->z += zs;
	}
}

void	bresenham_dx(t_param *param, t_point *p, int color)
{
	int	e;
	int	dx;
	int	dz;
	int	xs;
	int	zs;

	e = ft_abs(p[1].x - p[0].x);
	dx = 2 * e;
	dz = 2 * ft_abs(p[1].z - p[0].z);
	xs = p[1].x > p[0].x ? 1 : -1;
	zs = p[1].z > p[0].z ? 1 : -1;
	while (p->x != p[1].x + xs && p->x >= 0 && p->x <= param->mlx.width)
	{
		if (p->x > 0 && p->x < param->mlx.width
			&& p->z > 0 && p->z < param->mlx.height)
			param->mlx.pixels[p->x + p->z * param->mlx.width] = color;
		e -= dz;
		if (e < 0)
		{
			p->z += zs;
			e += dx;
		}
		p->x += xs;
	}
}

void	bresenham(t_param *param, t_point *p, int color)
{
	if (ft_abs(p[1].x - p[0].x) > ft_abs(p[1].z - p[0].z))
		bresenham_dx(param, p, color);
	else
		bresenham_dz(param, p, color);
}
