/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:02:40 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:32:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*s_s;

	s_s = (char*)s;
	i = -1;
	while (++i < len)
		s_s[i] = c;
	return (s);
}
