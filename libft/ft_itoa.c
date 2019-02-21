/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:37:44 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:28:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ten_power_n(int n)
{
	int		tpn;

	tpn = 1;
	while (n)
	{
		tpn *= 10;
		n--;
	}
	return (tpn);
}

char		*ft_itoa(int n)
{
	char	*sn;
	int		sign;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = -1;
	len = 0;
	sign = (n < 0) ? -1 : 0;
	n = (n < 0) ? -n : n;
	while (len < 10 && n >= ft_ten_power_n(len))
		len++;
	len = (len > 0) ? len : 1;
	if (!(sn = (char*)malloc(sizeof(char) * (len + 1 - sign))))
		return (NULL);
	if (sign == -1)
		sn[++i] = '-';
	while (len)
	{
		sn[++i] = '0' + ((n / ft_ten_power_n(len - 1)) % 10);
		len--;
	}
	sn[++i] = '\0';
	return (sn);
}
