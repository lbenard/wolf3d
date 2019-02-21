/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:12:58 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:31:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest_s;
	unsigned char	*src_s;

	dest_s = (unsigned char*)dest;
	src_s = (unsigned char*)src;
	i = -1;
	while (++i < len)
		dest_s[i] = src_s[i];
	return (dest);
}
