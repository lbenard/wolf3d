/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:17:35 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/17 18:20:20 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "libft.h"

void	*manage_error(t_param *p, int code, const char *message)
{
	ft_putstr(message);
	return (end(p, code));
}
