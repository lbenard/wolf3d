/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:07:50 by pp                #+#    #+#             */
/*   Updated: 2019/02/21 20:32:51 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include   "libft.h"

int    initialize_map(t_param *p)
{
    char    *line;
    
    get_next_line(p->map.file_descriptor, &line);
    p->map.width = ft_atoi(line);
    get_next_line(p->map.file_descriptor, &line);
    p->map.height = ft_atoi(line);
    if (!(p->map.map = malloc(sizeof(int) * p->map.width * p->map.height)))
        return (!manage_error(p, 0, "malloc() --> initialize_map error\n"));
    return (0);
}

void    parsing_map(t_param *p)
{
    char    *line;
    int        i;
    int        j;

    j = -1;
    initialize_map(p);
    while (get_next_line(p->map.file_descriptor, &line) > 0)
    {
        i = 0;
        while (line[i])
        {
            p->map.map[++j] = ft_atoi(&line[i]);
            if (!(j % 10))
                printf("\n");
            printf("%d\t", p->map.map[j]);
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
} 