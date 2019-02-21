/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:33:16 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:52:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*t;
	int		i;
	int		j;

	t = (char*)s;
	j = 0;
	while (t[j] && (t[j] == ' ' || t[j] == ',' || t[j] == '\n' || t[j] == '\t'))
		j++;
	if (!t[j])
		return (ft_strdup(""));
	i = ft_strlen(t) - 1;
	while (i > 0 && (t[i] == ' ' || t[i] == ',' || t[i] == '\n' ||
		t[i] == '\t'))
		i--;
	return (ft_strsub(t, j, i + 1 - j));
}
