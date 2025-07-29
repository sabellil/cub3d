/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:32:28 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/24 16:32:54 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed_bonus.h"
int	on_key_press(int keycode, t_infra *infra)
{
	t_game_data *game;

	game = &infra->data->game;
	if (keycode == XK_Escape)
		close_window(infra);
	else if (keycode == XK_w || keycode == XK_W)
		game->key_w = PRESSED;
	else if (keycode == XK_s || keycode == XK_S)
		game->key_s = PRESSED;
	else if (keycode == XK_a || keycode == XK_A)
		game->key_a = PRESSED;
	else if (keycode == XK_d || keycode == XK_D)
		game->key_d = PRESSED;
	else if (keycode == XK_Left)
		game->key_left = PRESSED;
	else if (keycode == XK_Right)
		game->key_right = PRESSED;
	return (SUCCESS);
}

int	on_key_release(int keycode, t_infra *infra)
{
	t_game_data *game;
	
	game = &infra->data->game;
	if (keycode == XK_w || keycode == XK_W)
		game->key_w = RELEASED;
	else if (keycode == XK_s || keycode == XK_S)
		game->key_s = RELEASED;
	else if (keycode == XK_a || keycode == XK_A)
		game->key_a = RELEASED;
	else if (keycode == XK_d || keycode == XK_D)
		game->key_d = RELEASED;
	else if (keycode == XK_Left)
		game->key_left = RELEASED;
	else if (keycode == XK_Right)
		game->key_right = RELEASED;
	return (SUCCESS);
}
int	is_walkable_cell(t_game_data *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_height)
		return (0);
	if ((int)ft_strlen(game->map[x]) <= y)
		return (0);
	if (game->map[x][y] == '1' || game->map[x][y] == ' ')
		return (0);
	return (1);
}

int	can_move_to_pos(t_game_data *game, float x, float y)
{
	float	r;
	int		cx;
	int		cy;

	r = 0.2f;
	cx = (int)(x - r);
	cy = (int)(y - r);
	if (!is_walkable_cell(game, cx, cy))
		return (0);
	cx = (int)(x - r);
	cy = (int)(y + r);
	if (!is_walkable_cell(game, cx, cy))
		return (0);
	cx = (int)(x + r);
	cy = (int)(y - r);
	if (!is_walkable_cell(game, cx, cy))
		return (0);
	cx = (int)(x + r);
	cy = (int)(y + r);
	if (!is_walkable_cell(game, cx, cy))
		return (0);
	return (1);
}

int	move_up(t_infra *infra)
{
	t_game_data	*game;
	float		new_x;
	float		new_y;

	game = &infra->data->game;
	new_x = game->pos_x + 0.05 * game->dir_y;
	new_y = game->pos_y + 0.05 * game->dir_x;
	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_down(t_infra *infra)
{
	t_game_data	*game;
	float		new_x;
	float		new_y;

	game = &infra->data->game;
	new_x = game->pos_x - 0.05 * game->dir_y;
	new_y = game->pos_y - 0.05 * game->dir_x;
	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_left(t_infra *infra)
{
	t_game_data	*game;
	float		new_x;
	float		new_y;

	game = &infra->data->game;
	new_x = game->pos_x - 0.05 * game->dir_x;
	new_y = game->pos_y + 0.05 * game->dir_y;
	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_right(t_infra *infra)
{
	t_game_data	*game;
	float		new_x;
	float		new_y;

	game = &infra->data->game;
	new_x = game->pos_x + 0.05 * game->dir_x;
	new_y = game->pos_y - 0.05 * game->dir_y;
	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_turn(t_infra *infra, int keycode)
{
	if (keycode == XK_Left)
		infra->data->game.angle -= 0.05;
	if (keycode == XK_Right)
		infra->data->game.angle += 0.05;
	infra->data->game.dir_x = cos(infra->data->game.angle);
	infra->data->game.dir_y = sin(infra->data->game.angle);
	return (SUCCESS);
}
