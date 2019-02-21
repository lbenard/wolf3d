/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:02:15 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:50:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *hay, const char *nee)
{
	int		i;
	int		j;

	i = -1;
	if (!*nee)
		return ((char*)hay);
	while (hay[++i])
	{
		j = 0;
		if (hay[i] == nee[j])
		{
			while (hay[i + j] == nee[j] && hay[i + j])
				j++;
			if (nee[j] == '\0')
				return ((char*)&hay[i]);
		}
	}
	return (NULL);
}
