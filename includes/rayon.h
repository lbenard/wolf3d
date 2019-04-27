#ifndef RAYON_H
# define RAYON_H
# include "maths.h"

typedef struct	s_ray
{
	t_pos2d position;
	t_pos2d increment;
	double	distance;
	char	direction;
	t_pos2d	shift;
	int	hit;
}		t_ray;

typedef struct	s_angle
{
	double	rad;
	double	cos;
	double	sin;
	double	tan;
}		t_angle;

t_angle	new_angle(double radian);

#endif
