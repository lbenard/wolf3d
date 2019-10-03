/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 07:17:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 15:39:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <SFML/Graphics.h>
# include "engine/module.h"

typedef sfImage	t_image;

t_heap_module_factory	image_from_file(const char *const path);

#endif
