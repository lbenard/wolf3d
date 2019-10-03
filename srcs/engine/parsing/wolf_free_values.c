/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:18:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:00:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "engine/parsing.h"

void	wolf_free_values(char **values)
{
	size_t	i;

	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
}
