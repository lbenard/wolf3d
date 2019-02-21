/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:51:11 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:47:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t		i;
	size_t		src_len;

	src_len = ft_strlen((char*)src);
	i = -1;
	while (++i < len && src[i])
		dest[i] = src[i];
	if (src_len < len)
		while (i < len)
		{
			dest[i] = '\0';
			i++;
		}
	return (dest);
}
