/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_strsplit_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:35:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:01:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"

size_t	wolf_strsplit_length(char **strings)
{
	size_t	length;

	length = 0;
	while (strings && strings[length])
		length++;
	return (length);
}
