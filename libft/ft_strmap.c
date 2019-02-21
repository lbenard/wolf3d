/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:28:02 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:45:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;
	char	*src;

	src = (char*)s;
	if (!(dest = malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = f(src[i]);
	dest[i] = '\0';
	return (dest);
}
