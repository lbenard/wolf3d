/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:13:00 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/15 01:59:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*s1_s;
	unsigned char	*s2_s;

	s1_s = (unsigned char*)s1;
	s2_s = (unsigned char*)s2;
	i = -1;
	while (++i < len)
		if (s1_s[i] != s2_s[i])
			return (s1_s[i] - s2_s[i]);
	return (0);
}
