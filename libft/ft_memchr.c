/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:53:23 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/15 00:33:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*s_s;

	s_s = (unsigned char*)s;
	i = -1;
	while (++i < len)
		if (s_s[i] == (unsigned char)c)
			return ((void*)&(s_s[i]));
	return (NULL);
}
