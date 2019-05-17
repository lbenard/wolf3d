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

double	find_distance(t_pos2d hero, t_pos2d sprite)
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
	while (node->next && sprite->distance < node->distance)
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

void	render_sprites(int column, double width, t_obstacle *obstacle, t_obstacle sprite)
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
	add_sprite(column_start, sprite_width, obstacle, new_obstacle);
}

void	render_texture(t_param *p, int start, int width, t_sprite *sprite)
{
	double	column_texture;
	int	i;
	
	i = -1;
	if (start < 0)
		i = -start;
	while(++i < start && start + i < W_WIDTH)
	{
		column_texture = (double)i / (double)width;
		render_column(p, column_texture, sprite);
	}
}

void	render_sprite(t_param *p, t_hero hero, t_obstacle *obstacle, t_sprite *sprite)
{
	double	distance;
	double	angle;
	double	ratio;
	int		column_start;
	int		column_width;

	distance = find_distance(hero.position, sprite->position);
	angle = find_angle(*sprite, hero);
	ratio = find_sprite_ratio_position_in_view(hero, angle);
	column_width = (double)sprite->size.x / distance;
	column_start = (ratio * W_WIDTH) - ((double)column_width * 0.5);
	render_texture(p, column_start, column_width, sprite);
}

void	render_sprites(t_param *p, t_node *head, t_obstacle *obstacle)
{
	t_node *node;
	t_sprite *sprite;

	node = head;
	while ((node = node->next) != head)
	{
		sprite = (t_sprite*)node;
		render_sprite(p, p->hero, obstacle, sprite);
	}
}
