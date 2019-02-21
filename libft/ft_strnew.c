/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:04:11 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:48:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*v;

	i = -1;
	if (!(v = malloc(sizeof(char) * size + 1)))
		return (0);
	while (++i <= size)
		v[i] = '\0';
	return (v);
}
