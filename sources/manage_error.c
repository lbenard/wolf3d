/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:17:35 by ppetitea          #+#    #+#             */
/*   Updated: 2019/02/21 17:16:51 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"
#include "mlx.h"

void	*manage_error(t_param *p, int code, const char *message)
{
	ft_putstr(message);
	if (code > 2)
		mlx_destroy_image(p->mlx.init, p->mlx.img);
	if (code > 1)
		mlx_destroy_window(p->mlx.init, p->mlx.window);
	if (code > 0)
		free(p->mlx.init);
	return (NULL);
}
