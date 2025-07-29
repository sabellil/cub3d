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
	t_game_data	*game = &infra->data->game;
	float		new_x = game->pos_x + 0.2 * game->dir_y;
	float		new_y = game->pos_y + 0.2 * game->dir_x;

	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_down(t_infra *infra)
{
	t_game_data	*game = &infra->data->game;
	float		new_x = game->pos_x - 0.2 * game->dir_y;
	float		new_y = game->pos_y - 0.2 * game->dir_x;

	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_left(t_infra *infra)
{
	t_game_data	*game = &infra->data->game;
	float		new_x = game->pos_x - 0.2 * game->dir_x;
	float		new_y = game->pos_y + 0.2 * game->dir_y;

	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_right(t_infra *infra)
{
	t_game_data	*game = &infra->data->game;
	float		new_x = game->pos_x + 0.2 * game->dir_x;
	float		new_y = game->pos_y - 0.2 * game->dir_y;

	if (can_move_to_pos(game, new_x, new_y))
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}



// int	move_up(t_infra *infra)
// {
// 	t_game_data	*game;
// 	float		new_x;
// 	float		new_y;

// 	game = &infra->data->game;
// 	new_x = game->pos_x + 0.2 * game->dir_y;
// 	new_y = game->pos_y + 0.2 * game->dir_x;
// 	if (game->map[(int)new_x][(int)new_y] != '1')
// 	{
// 		game->pos_x = new_x;
// 		game->pos_y = new_y;
// 	}
// 	return (SUCCESS);
// }

// int	move_down(t_infra *infra)
// {
// 	t_game_data	*game;
// 	float		new_x;
// 	float		new_y;

// 	game = &infra->data->game;
// 	new_x = game->pos_x - 0.2 * game->dir_y;
// 	new_y = game->pos_y - 0.2 * game->dir_x;
// 	if (game->map[(int)new_x][(int)new_y] != '1')
// 	{
// 		game->pos_x = new_x;
// 		game->pos_y = new_y;
// 	}
// 	return (SUCCESS);
// }

// int	move_right(t_infra *infra)
// {
// 	t_game_data	*game;
// 	float		new_x;
// 	float		new_y;

// 	game = &infra->data->game;
// 	new_x = game->pos_x + 0.2 * game->dir_x;
// 	new_y = game->pos_y - 0.2 * game->dir_y;
// 	if (game->map[(int)new_x][(int)new_y] != '1')
// 	{
// 		game->pos_x = new_x;
// 		game->pos_y = new_y;
// 	}
// 	return (SUCCESS);
// }

// int	move_left(t_infra *infra)
// {
// 	t_game_data	*game;
// 	float		new_x;
// 	float		new_y;

// 	game = &infra->data->game;
// 	new_x = game->pos_x - 0.2 * game->dir_x;
// 	new_y = game->pos_y + 0.2 * game->dir_y;
// 	if (game->map[(int)new_x][(int)new_y] != '1')
// 	{
// 		game->pos_x = new_x;
// 		game->pos_y = new_y;
// 	}
// 	return (SUCCESS);
// }

int	move_turn(t_infra *infra, int keycode)
{
	if (keycode == XK_Left)
		infra->data->game.angle -= 0.2;
	if (keycode == XK_Right)
		infra->data->game.angle += 0.2;
	infra->data->game.dir_x = cos(infra->data->game.angle);
	infra->data->game.dir_y = sin(infra->data->game.angle);
	return (SUCCESS);
}
