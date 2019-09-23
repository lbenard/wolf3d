/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bloc_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:43:55 by ppetitea          #+#    #+#             */
/*   Updated: 2019/09/21 15:43:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"
#include "engine/error.h"
#include <stdlib.h>
#include <stdio.h>
t_bloc_node  *new_bloc_node(const char *key, char **values)
{
    t_bloc_node   *ret;
    int           values_amount;

    values_amount = 0;
    while (values && values[values_amount])
        values_amount++;
    if (values_amount != 4)
        return (throw_error_str("bad amount of values in bloc node"));
    if (!(ret = (t_bloc_node*)malloc(sizeof(t_bloc_node))))
        return (throw_error_str("failed while allocating bloc node"));
    init_list_head(&ret->node);
    ret->key = key;
    ret->north_texture_name = values[0];
    ret->east_texture_name = values[1];
    ret->south_texture_name = values[2];
    ret->west_texture_name = values[3];
    return (ret);
}