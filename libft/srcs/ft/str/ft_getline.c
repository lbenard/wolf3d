/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:45:13 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:36:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

const char	*ft_getline(const char *file, size_t line)
{
	while (line--)
		if ((file = ft_strchr(file, '\n')))
			file++;
	return (file);
}
