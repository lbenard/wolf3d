/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:18:50 by ppetitea          #+#    #+#             */
/*   Updated: 2019/01/24 20:24:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		contains_char(char *string, char c)
{
	if (!string)
		return (0);
	while (*string)
	{
		if (*string == c)
			return (1);
		string++;
	}
	return (0);
}
