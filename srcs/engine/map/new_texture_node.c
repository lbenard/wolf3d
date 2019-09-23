/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_texture_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:24:09 by ppetitea          #+#    #+#             */
/*   Updated: 2019/09/21 14:38:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"
#include "engine/error.h"

#include <stdlib.h>

t_texture_node  *new_texture_node(const char *name, const char *const path)
{
    t_texture_node  *ret;

    if (!(ret = (t_texture_node*)malloc(sizeof(t_texture_node))))
        return (throw_error_str("failed while allocating texture node"));
    if (!(ret->image = sfImage_createFromFile(path)))
    {
        free(ret);
        return (throw_error_str("failed while creating image"));
    }
    init_list_head(&ret->node);
    ret->name = name;
    return (ret);
}