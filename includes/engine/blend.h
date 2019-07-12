/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:31:57 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/10 00:44:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLEND_H
# define BLEND_H

# include "colors/rgba.h"

void	blend_add(t_rgba *const a, const t_rgba *const b);

#endif