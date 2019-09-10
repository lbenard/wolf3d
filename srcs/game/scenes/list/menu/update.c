/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/10 11:54:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"
#include "engine/game.h"
#include "engine/delta.h"
#include "engine/lookup_table.h"
#include "game/scenes/raycasting_scene.h"

static void	update_buttons(t_menu_scene *const self)
{
	double		wall;
	t_usize		mid;
	sfVector2i	mouse;

	wall = get_wall_time() / 5.0f;
	mouse = sfMouse_getPositionRenderWindow(game_singleton()->window.window);
	mid = ft_usize(self->window_size.x / 2, self->window_size.y / 2);
	self->start_game_ref->super.transform.position = ft_vec3f(
		cosine_lookup(wall - (int)wall) * 10.0f + mid.x
			- (mouse.x - (int)mid.x) / 50.0f
			- (self->start_game_ref->normal_texture.size.x / 2),
		sine_lookup(wall - (int)wall) * 5.0f + mid.y - 45
			- (mouse.y - (int)mid.y) / 50.0f
			- (self->start_game_ref->normal_texture.size.y / 2),
		0.0f);
	self->close_game_ref->super.transform.position = ft_vec3f(
		sine_lookup(wall - (int)wall) * 10.0f + mid.x
			- (mouse.x - (int)mid.x) / 50.0f
			- (self->close_game_ref->normal_texture.size.x / 2),
		sine_lookup(wall - (int)wall) * 5.0f + mid.y + 45
			- (mouse.y - (int)mid.y) / 50.0f
			- (self->close_game_ref->normal_texture.size.y / 2),
		0.0f);
}

void		menu_scene_update(t_menu_scene *const self)
{
	entity_list_update(&self->super.entities);
	if (self->start_game_ref->is_clicked || sfKeyboard_isKeyPressed(sfKeyEnter))
	{
		game_set_scene(raycasting_scene(&game_singleton()->window));
		return ;
	}
	if (self->close_game_ref->is_clicked)
		window_close(&game_singleton()->window);
	update_buttons(self);
}