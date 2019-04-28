/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:30:44 by pp                #+#    #+#             */
/*   Updated: 2019/03/17 19:09:21 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

int	main(int ac, char **av)
{
	t_param p;

	if (start(&p, ac, av))
        manage_error(&p, END, "start --> error\n");
	loop(&p);
	return (0);
}