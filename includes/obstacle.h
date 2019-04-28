#ifndef OBSTACLE_H
# define OBSTACLE_H

# include "maths.h"
# include "rayon.h"

typedef struct			s_obstacle
{
	t_pos2d			position;
	double			distance;
	char			direction;
	int			type;
	int			size;
	struct s_obstacle	*next;
}				t_obstacle;

t_obstacle	create_obstacle(t_ray rayon);

#endif
