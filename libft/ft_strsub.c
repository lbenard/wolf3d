/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:32:39 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:51:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (0);
	i = -1;
	start--;
	while (++i < len && s[++start])
		dest[i] = s[start];
	dest[i] = '\0';
	return (dest);
}
