#ifndef SPRITE_H
# define SPRITE_H

# include "../includes/array.h"

typedef struct		s_sprite
{
	t_pos2d		position;
	t_size		size;
	int		type;
	struct s_sprite	*next;
}			t_sprite;

#endif
