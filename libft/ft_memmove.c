/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:25 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:32:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	int		i;
	int		leni;
	int		inv;
	char	*dest_s;
	char	*src_s;

	leni = (int)len;
	dest_s = (char*)dest;
	src_s = (char*)src;
	i = -1;
	inv = 0;
	while (++i < leni)
		if (src_s + i == dest_s)
			inv = 1;
	i = (inv) ? leni : -1;
	if (inv)
		while (--i >= 0)
			dest_s[i] = src_s[i];
	else
		while (++i < leni)
			dest_s[i] = src_s[i];
	return (dest);
}
