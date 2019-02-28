/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/28 18:06:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "engine/errors.h"
#include "engine/framebuffer.h"
#include "containers/list.h"
#include "game/entities/entity_type.h"
#include "game/entities/test_entity.h"
#include "game/entities/dummy_entity.h"
#include "colors/hsv.h"
#include "colors/rgb.h"
#include "engine/delta.h"

#define WIDTH 1280
#define HEIGHT 720

static void	print_entity(t_entity_list *entity_list)
{
	if (entity_list->entity->type == DUMMY_ENTITY_TYPE)
	{
		t_dummy_entity	*dummy = dummy_entity_from_entity(entity_list->entity);
		printf("Dummy entity: Pos: {x: %f y: %f z: %f}\n",
			dummy->super.transform.position.x,
			dummy->super.transform.position.y,
			dummy->super.transform.position.z);
	}
	else if (entity_list->entity->type == TEST_ENTITY_TYPE)
	{
		t_test_entity	*test = test_entity_from_entity(entity_list->entity);
		printf("Test entity: data: %d\n", test->data);
		printf("             Pos: {x: %f y: %f z: %f}\n",
			test->super.transform.position.x,
			test->super.transform.position.y,
			test->super.transform.position.z);
	}
}

// static void	test_entity_list(void)
// {
// 	t_list_head entity_list;

// 	init_list_head(&entity_list);
// 	list_add_entry(&new_entity_list(&new_test_entity(42)->super)->node,
// 		&entity_list);
// 	list_add_entry(&new_entity_list(&new_test_entity(21)->super)->node,
// 		&entity_list);
// 	list_add_entry(&new_entity_list(&new_dummy_entity()->super)->node,
// 		&entity_list);
// 	list_foreach(&entity_list, __builtin_offsetof(t_entity_list, node),
// 		print_entity);
// 	list_foreach(&entity_list, __builtin_offsetof(t_entity_list, node),
// 		free_entity_list);
// }

#include "game/scenes/menu_scene.h"
#include "game/scenes/scene_type.h"

// static void	test_scene(void)
// {
// 	size_t			i;

// 	printf("%s (%d)\n", scene->super.name, scene->super.type);
// 	i = 42;
// 	while (i--)
// 	{
// 	}
// 	free_menu_scene(scene);
// }

int		main(void)
{
	sfVideoMode		mode;
	sfRenderWindow	*window;
	sfEvent			event;
	t_framebuffer	framebuffer;
	t_menu_scene	*scene;

	// test_entity_list();
	// test_scene();
	// return (0);
	scene = new_menu_scene();
	list_add_entry(&new_entity_list(&new_test_entity(42)->super)->node,
		&scene->super.entities);
	mode.width = WIDTH;
	mode.height = HEIGHT;
	mode.bitsPerPixel = 64;
	if (!(window = sfRenderWindow_create(mode, "wolf3d", sfClose, NULL)))
		return (-1);
	if (!init_framebuffer(&framebuffer, ft_usize(WIDTH, HEIGHT)))
		return (!throw_result_str("Error while creating framebuffer"));
	while (sfRenderWindow_isOpen(window))
	{
		static clock_t	last_time = 0.0;
		static double	spf = 0.0;
		framebuffer_clear(&framebuffer);
		for (size_t y = 0; y < HEIGHT; y++)
			for (size_t x = 0; x < WIDTH; x++)
				framebuffer.framebuffer[WIDTH * y + x] = hsv_to_int(ft_hsv((x / (double)WIDTH * 360.0), y / (double)HEIGHT, 1.0f));
				// framebuffer.framebuffer[WIDTH * y + x] = 0xFFFFFFFF;
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
				event.key.code == sfKeyEscape))
				sfRenderWindow_close(window);
		}
		scene_type_update(&scene->super);
		scene_type_render(&scene->super);
		list_foreach(&scene->super.entities,
			__builtin_offsetof(t_entity_list, node), print_entity);
		spf = ((double)(clock() - last_time) / CLOCKS_PER_SEC);
		set_last_delta(spf);
		printf("%.2ffps\t(%.3fms)\n", 1 / spf, spf * 1000.0f);
		last_time = clock();
		framebuffer_update(&framebuffer);
		framebuffer_display(&framebuffer, window);
	}
	sfRenderWindow_destroy(window);
	free_framebuffer(&framebuffer);
	return (0);
}
