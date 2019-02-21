/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:38:06 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/16 06:09:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*s2;
	int		i;

	if (!(s2 = malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (s1[++i] && i < (int)size - 1)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
