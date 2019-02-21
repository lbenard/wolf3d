/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:24:16 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:43:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen((char*)dest);
	src_len = ft_strlen((char*)src);
	if (size < dest_len)
		return (src_len + size);
	i = dest_len - 1;
	while (++i < size - 1)
		dest[i] = src[i - dest_len];
	dest[i] = '\0';
	return (dest_len + src_len);
}
