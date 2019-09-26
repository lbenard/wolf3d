/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:43:55 by ppetitea          #+#    #+#             */
/*   Updated: 2019/09/25 18:52:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/parsing.h"
#include "engine/error.h"

t_block_node	*new_block_node(const char *key, char **values)
{
	t_block_node	*ret;
	int				values_amount;

	if (!key)
	{
		wolf_free_values(values);
		return (throw_error_str("new_block_node(): ""invalid key"));
	}
	if (!values)
	{
		free((char*)key);
		return (throw_error_str("new_block_node(): ""invalid values"));
	}
	values_amount = 0;
	while (values[values_amount])
		values_amount++;
	if (values_amount != 4)
	{
		free((char*)key);
		wolf_free_values(values);
		return (throw_error_str("new_block_node(): "
			"bad amount of values in block node"));
	}
	if (!(ret = (t_block_node*)malloc(sizeof(t_block_node))))
	{
		free((char*)key);
		wolf_free_values(values);
		return (throw_error_str("new_block_node(): "
			"failed while allocating block node"));
	}
	init_list_head(&ret->node);
	ret->key = key;
	ret->north_texture_name = values[0];
	ret->east_texture_name = values[1];
	ret->south_texture_name = values[2];
	ret->west_texture_name = values[3];	
	free(values);
	return (ret);
}