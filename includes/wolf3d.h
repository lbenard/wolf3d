/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:16:07 by pp                #+#    #+#             */
/*   Updated: 2019/04/15 19:29:46 by ppetitea         ###   ########.fr       */
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
# include "../includes/bitmap.h"
# include "../includes/obstacle.h"
# include "../includes/maths.h"
# include "../includes/textures.h"
# include "../includes/sprite.h"
# include "../includes/array.h"

# define END -42
# define W_WIDTH 1080
# define W_HEIGHT 720
# define WALL 1
# define LIMIT 0
# define SPRITE 2

typedef struct 			s_dpoint_2d
{
	double				x;
	double				y;
}						t_dpoint_2d;

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
	t_dpoint_2d		*rays;
	double			w_ratio;
	double			h_ratio;
	t_bitmap_image	*texture;
}                   t_map;

typedef struct		s_field_of_view
{
	double		direction;
	double		angle;
}			t_field_of_view;

typedef	struct		s_entity
{
	t_pos2d		position;
}			t_entity;

typedef struct 		s_hero
{
	t_pos2d		position;
	t_field_of_view	view;
}			t_hero;

typedef struct		s_param
{
	t_mlx_params    mlx;
	t_pointeur      pointeur;
	t_mouse         mouse;
	t_keybord       keyboard;
	t_map           map;
	t_hero		hero;
	t_entity	horizontal_wall;
	t_entity	vertical_wall;
	t_entity	wall;
	t_obstacle	*obstacle;
	t_bitmap_image	**texture;
	t_sprite	*sprite;
}			t_param;

int     start(t_param *p, int ac, char **av);
void    check_inputs(t_param *p, int ac, char **av);
int     initialize_mlx_params(t_param *p);
int     initialize_map_params(t_param *p);
int     initialize_textures(t_param *p);
int     initialize_hero_params(t_param *p);
int     initialize_callbacks_params(t_param *p);
int     parse_map(t_param *p);

void    loop(t_param *p);
int		press_callback(int key, void *param);
int		release_callback(int key, void *param);
int		pointer_callback(int x, int y, void *param);
int		mouse_callback(int button, int x, int y, void *param);
int		manage_callback(void *param);
void	manage_keyboard(t_param *p);
void	manage_hero_vector_direction(t_param *p);
void	manage_hero_moves(t_param *p);


void	draw_3dmap(t_param *p, t_obstacle *obstacle);
void	draw(t_param *p);
void	reset_image(t_param *p);
void	print_fps(t_param *p);
void	render_3dmap(t_param *p);
void	render_sprites(t_param *p, t_sprite *sprite, t_obstacle *obstacle);
int     search_wall(t_param *p, double direction);
//void	find_distance(t_param *p);
//void    render_column(t_param *p, double distance, int column);
void    render_2d_map(t_param *p);
void	render_hero(t_param *p);
void	render_hero_vector(t_param *p);
void	render_2d_visible_surface(t_param *p, int color);
void	bresenham_dx(t_param *param, t_point *p, int color);
void	bresenham_dz(t_param *param, t_point *p, int color);
void	bresenham(t_param *param, t_point *p, int color);

void	search_vertical_wall(t_param *p, double x, double y);
void	search_horizontal_wall(t_param *p, double x, double y);

void	*manage_error(t_param *p, int code, const char *message);
void    *end(t_param *p, int code);

#endif
