/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dmap_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:05:46 by ppetitea          #+#    #+#             */
/*   Updated: 2019/04/15 19:40:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/obstacle.h"
#include "../includes/rayon.h"
#include "../includes/bitmap.h"
#include "libft.h"

double	find_distance(t_pos2d sprite, t_pos2d hero)
{
	t_pos2d distance;
	double	res;

	distance.x = sprite.x - hero.x;
	distance.y = sprite.y - hero.y;
	res = sqrt(distance.x * distance.x + distance.y * distance.y);
	if (res < 1)
		res = 1;
	return (res);
}

double	find_angle(t_sprite sprite, t_hero hero)
{
	double angle;
	double adjacent;
	double oppose;

	adjacent = sprite.position.x - hero.position.x;
	oppose = sprite.position.y - hero.position.y;
	angle = atan(oppose / adjacent) * (M_PI / 180.0);
	return (angle);
}

double	find_sprite_ratio_position_in_view(t_hero hero, double sprite_angle)
{
	double	min;
	double	max;
	double	ratio;

	min = hero.view.direction - (M_PI / 6.0);
	max = hero.view.direction + (M_PI / 6.0);
	ratio = (sprite_angle - min) / (max - min);
	return (ratio);
}

void	add_obstacle_to_column(t_obstacle *sprite, t_obstacle *start)
{
	t_obstacle *node;

	node = start;
	while (sprite->distance < node->distance && node->next)
		node = node->next;
	if (node->next)
		sprite->next = node->next;
	node->next = sprite;
	printf("type %d\n",node->next->type);
}

t_obstacle	*duplicate_obstacle(t_obstacle obstacle)
{
	t_obstacle *new_obstacle;

	new_obstacle = malloc(sizeof(t_obstacle));
	new_obstacle->distance = obstacle.distance;
	new_obstacle->position = obstacle.position;
	new_obstacle->size = obstacle.size;
	new_obstacle->type = obstacle.type;
	new_obstacle->direction = obstacle.direction;
	new_obstacle->texture_column_ratio = obstacle.texture_column_ratio;
	new_obstacle->next = obstacle.next;
	return (new_obstacle);
}

void	add_sprite(int column, double width, t_obstacle *obstacle, t_obstacle sprite)
{
	double	x;
	t_obstacle *new_sprite;

	x = 0;
	if (column < 0)
	{
		x = -column;
		column = 0;
	}
	while (column < W_WIDTH && x < width)
	{
		sprite.texture_column_ratio = x / width;
		new_sprite = duplicate_obstacle(sprite);
		printf("obstacle[%d].distance %lf\n", column, obstacle[column].distance);
		printf("sprite->distance %lf\n", sprite.distance);
		if (sprite.distance < obstacle[column].distance)
			add_obstacle_to_column(new_sprite, &(obstacle[column]));
		column++;
		x++;
	}
}

void	add_sprite_to_obstacle_list(t_hero hero, t_obstacle *obstacle, t_sprite sprite)
{
	t_obstacle	new_obstacle;
	double	ratio;
	double	angle;
	int	column_start;
	double	sprite_width;

	angle = find_angle(sprite, hero);
	new_obstacle.distance = find_distance(sprite.position, hero.position);
	new_obstacle.position = sprite.position;
	new_obstacle.size = sprite.size.y;
	new_obstacle.type = sprite.type;
	new_obstacle.direction = angle - M_PI;
	new_obstacle.next = NULL;
	ratio = find_sprite_ratio_position_in_view(hero, angle);
	column_start = (ratio * W_WIDTH) - ((double)sprite.size.x * 0.5)
		/ new_obstacle.distance;
	sprite_width = (double)sprite.size.x / new_obstacle.distance;
	//printf("column %d\n", column_start);/////
	add_sprite(column_start, sprite_width, obstacle, new_obstacle);
	printf("sprite d\n");
}

void	render_sprites(t_param *p, t_sprite *sprite, t_obstacle *obstacle)
{
	while (sprite)
	{
		add_sprite_to_obstacle_list(p->hero, obstacle, *sprite);
		printf("%lf\n",obstacle[530].next->position.x);
		sprite = sprite->next;
	}
}
