#ifndef SPRITE_H
# define SPRITE_H

# include "../includes/array.h"
# include "../includes/list.h"

typedef struct		s_sprite
{
	t_node		node;
	t_pos2d		position;
	double		size;
	int			type;
}			t_sprite;

#endif
