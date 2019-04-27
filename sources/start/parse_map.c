/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:48:41 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 19:18:38 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include   "libft.h"

int    parse_map(t_param *p)
{
    char    *line;
    int     i;
    int     j;

    j = -1;
    while (get_next_line(p->map.file_descriptor, &line) > 0)
    {
        i = 0;
        while (line[i])
        {
            p->map.map[++j] = ft_atoi(&line[i]);
            i++;
            while (line[i] && (!i || !ft_is_space(line[i - 1])
                || !ft_is_number(line[i])))
                i++;
        }
    }
    return (0);
}
