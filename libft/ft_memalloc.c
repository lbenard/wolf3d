/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:37:30 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:28:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*v;

	i = -1;
	if (!(v = malloc(sizeof(unsigned char) * size)))
		return (0);
	while (++i < size)
		v[i] = '\0';
	return ((void*)v);
}
