/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 02:12:19 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:41:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	char	*s1_s;
	char	*s2_s;
	int		i;

	s1_s = (char*)s1;
	s2_s = (char*)s2;
	i = 0;
	while (s1_s[i] == s2_s[i] && s1_s[i])
		i++;
	if (!(s1_s[i] - s2_s[i]))
		return (1);
	return (0);
}
