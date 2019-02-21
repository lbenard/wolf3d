/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:25:49 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/16 05:08:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	char	*s1_s;
	char	*s2_s;
	int		i;

	s1_s = (char*)s1;
	s2_s = (char*)s2;
	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen(s1_s) + ft_strlen(s2_s)
		+ 1)))
		return (NULL);
	i = -1;
	while (s1_s && *s1_s)
		dest[++i] = *s1_s++;
	while (s2_s && *s2_s)
		dest[++i] = *s2_s++;
	dest[i + 1] = '\0';
	return (dest);
}
