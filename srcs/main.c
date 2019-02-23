/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:17:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/22 19:50:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int main()
{
	sfVideoMode mode = {900, 600, 32};
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	sfEvent event;

	/* Create the main window */
	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if (!window)
		return 1;

	/* Load a sprite to display */
	texture = sfTexture_createFromFile("merguez.jpg", NULL);
	if (!texture)
		return 1;
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);

	/* Start the game loop */
	while (sfRenderWindow_isOpen(window))
	{
		/* Process events */
		while (sfRenderWindow_pollEvent(window, &event))
		{
			/* Close window : exit */
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}

		/* Clear the screen */
		sfRenderWindow_clear(window, sfBlack);

		/* Draw the sprite */
		sfRenderWindow_drawSprite(window, sprite, NULL);

		/* Update the window */
		sfRenderWindow_display(window);
	}

	/* Cleanup resources */
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);

	return 0;
}
