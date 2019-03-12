/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:16:07 by pp                #+#    #+#             */
/*   Updated: 2019/03/12 14:42:49 by ppetitea         ###   ########.fr       */
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

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct          s_vector2d
{
    float               x;
    float               y;
}                       t_vector2d;

typedef struct          s_point2d
{
    int                 x;
    int                 y;
}                       t_point2d;

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
	float			zoom;
}                   t_map;

typedef	struct		s_entity
{
	float			x;
	float			y;
	float			vector_direction;
}					t_entity;

typedef struct      s_view
{
    double          distance;
    double          fisheye_correction;
    double          cos;
    double          sin;
    double          tan;
    double          dist_to_h_wall;
    double          dist_to_v_wall;
    int             h_hit;
    int             v_hit;
}                   t_view;

typedef struct		s_param
{
	t_mlx_params    mlx;
    t_pointeur      pointeur;
    t_mouse         mouse;
    t_keybord       keyboard;
    t_map           map;
	t_entity		hero;
	t_entity		horizontal_wall;
	t_entity		vertical_wall;
    t_view          view;
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
int                 parsing_map(t_param *p);
void                render_2d_map(t_param *p);
void     			render_3d_map(t_param *p);
void				initialize_hero(t_param *p);
int    				initialize_map(t_param *p);
void				bresenham(t_param *param, t_point *p, int color);
void				search_vertical_intersection(t_param *p, double x, double y);
void				search_horizontal_intersection(t_param *p, double x, double y);
void				render_2d_visible_surface(t_param *p, double x, double y, int color);

#endif