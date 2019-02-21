/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:30:02 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/15 02:06:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest_s;
	unsigned char	*src_s;

	dest_s = (unsigned char*)dest;
	src_s = (unsigned char*)src;
	i = -1;
	while (++i < len && src_s[i] != (unsigned char)c)
		dest_s[i] = src_s[i];
	if (i < len && src_s[i] == (unsigned char)c)
	{
		dest_s[i] = (unsigned char)c;
		return (&(dest_s[i + 1]));
	}
	else
		return (NULL);
}
