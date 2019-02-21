/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 00:09:23 by pp                #+#    #+#             */
/*   Updated: 2019/02/03 00:13:47 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_u32	ft_rgb_to_int(t_rgb color)
{
	int	result;

	result = color.r;
	result <<= 8;
	result += color.g;
	result <<= 8;
	result += color.b;
	return (result);
}