/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:07:50 by pp                #+#    #+#             */
/*   Updated: 2019/02/23 13:46:40 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include   "libft.h"

int    initialize_map(t_param *p)
{
    char    *line;
    
	p->map.zoom = 0.2;
    get_next_line(p->map.file_descriptor, &line);
    p->map.width = ft_atoi(line);
    get_next_line(p->map.file_descriptor, &line);
    p->map.height = ft_atoi(line);
    if (!(p->map.map = malloc(sizeof(int) * p->map.width * p->map.height)))
        return (!manage_error(p, 0, "malloc() --> initialize_map error\n"));
    initialize_hero(p);
    return (0);
}

int    parsing_map(t_param *p)
{
    char    *line;
    int        i;
    int        j;

    j = -1;
    if (initialize_map(p))
        return (!manage_error(p, 0, "initialize_map() --> parsing error\n"));
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
    
    /*i = -1;
    while (++i < 10)
    {
        j = -1;
        while (++j < 10)
            printf("%d\t", p->map.map[i * 10 + j]);
        printf("\n");
    }*/
    return (0);
} 