/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pp <pp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:16:07 by pp                #+#    #+#             */
/*   Updated: 2019/02/21 20:10:04 by pp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "mlx_keys_macos.h"

typedef struct      s_pointeur
{
    double          x;
    double          y;
    int             inside;
}                   t_pointeur;

typedef struct      s_mouse
{
    int             button;
    int             press;
    double          x;
    double          y;
}                   t_mouse;

typedef struct      s_keyboard
{
    int             key;
    int             press;
}                   t_keybord;

typedef struct      s_mlx_params
{
    void			*init;
	void			*window;
	void			*img;
	int				*pixels;
	int				width;
	int				height;
}                   t_mlx_params;

typedef struct      s_map
{
    int             file_descriptor;
    int             *map;
    int             width;
    int             height;
}                   t_map;

typedef struct		s_param
{
	t_mlx_params    mlx;
    t_pointeur      pointeur;
    t_mouse         mouse;
    t_keybord       keyboard;
    t_map           map;
}					t_param;

void				*manage_error(t_param *p, int code, const char *message);
int					manage_callback(void *param);
int					press_callback(int key, void *param);
int					release_callback(int key, void *param);
int					pointer_callback(int x, int y, void *param);
int					mouse_callback(int button, int x, int y, void *param);
void				reset_image(t_param *p);
void				draw(t_param *p);
void				print_fps(t_param *p);
void                parsing_map(t_param *p);

#endif