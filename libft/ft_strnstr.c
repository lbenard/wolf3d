/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:41:52 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:49:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*nee)
		return ((char*)hay);
	i = -1;
	while (++i < len && hay[i])
	{
		j = 0;
		if (hay[i] == nee[j])
		{
			while (hay[i + j] == nee[j] && nee[j] && i + j < len)
				j++;
			if (!nee[j])
				return ((char*)&hay[i]);
		}
	}
	return (NULL);
}
