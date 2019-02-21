/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:13:08 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/15 01:30:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(int n, int fd)
{
	if (n < 0 && n / 10)
		ft_recursive(n / 10, fd);
	ft_putchar_fd('0' - n % 10, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n = -n;
	else
		ft_putchar_fd('-', fd);
	ft_recursive(n, fd);
}
