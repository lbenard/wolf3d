/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:32:47 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 18:20:06 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "mlx.h"

void    *end(t_param *p, int code)
{
    if (code > 2)
		mlx_destroy_image(p->mlx.init, p->mlx.img);
	if (code > 1)
		mlx_destroy_window(p->mlx.init, p->mlx.window);
	if (code > 0)
		free(p->mlx.init);
	if (code == END)
		exit(0);
	return (NULL);
}