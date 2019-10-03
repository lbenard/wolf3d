/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:47:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 15:32:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELTA_H
# define DELTA_H

void	set_last_delta(const float delta);
float	get_last_delta(void);
float	*get_delta_ptr(void);
double	get_wall_time(void);

#endif
