#ifndef TEXTURES_H
# define TEXTURES_H

enum	e_textures
{
	LIMIT,
	WALL,
	SPRITE
};

typedef	struct	s_textures
{
	t_bitmap_image *limit;
	t_bitmap_image *wall;
	t_bitmap_image *sprite;
}		t_textures;

#endif
