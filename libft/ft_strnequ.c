/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:30:42 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/15 01:39:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	char	*s1_s;
	char	*s2_s;
	size_t	i;

	s1_s = (char*)s1;
	s2_s = (char*)s2;
	i = 0;
	while (s1_s[i] == s2_s[i] && s1_s[i] && i + 1 < n)
		i++;
	if (!n || !(s1_s[i] - s2_s[i]))
		return (1);
	return (0);
}
