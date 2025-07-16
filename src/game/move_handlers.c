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

#include "../../include/cubed.h"

int	move_up(t_infra *infra)
{
	t_game_data *game = &infra->data->game;
	float new_x = game->pos_x + 0.2f * game->dir_y;
	float new_y = game->pos_y + 0.2f * game->dir_x;

	if (
		game->map[(int)(new_y + 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y + 0.2f)][(int)(new_x - 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x - 0.2f)] != '1'
	)
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}
int	move_down(t_infra *infra)
{
	t_game_data *game = &infra->data->game;
	float new_x = game->pos_x - 0.2f * game->dir_y;
	float new_y = game->pos_y - 0.2f * game->dir_x;

	if (
		game->map[(int)(new_y + 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y + 0.2f)][(int)(new_x - 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x - 0.2f)] != '1'
	)
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}
int	move_left(t_infra *infra)
{
	t_game_data *game = &infra->data->game;
	float new_x = game->pos_x - 0.2f * game->dir_x;
	float new_y = game->pos_y + 0.2f * game->dir_y;

	if (
		game->map[(int)(new_y + 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y + 0.2f)][(int)(new_x - 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x - 0.2f)] != '1'
	)
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}

int	move_right(t_infra *infra)
{
	t_game_data *game = &infra->data->game;
	float new_x = game->pos_x + 0.2f * game->dir_x;
	float new_y = game->pos_y - 0.2f * game->dir_y;

	if (
		game->map[(int)(new_y + 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y + 0.2f)][(int)(new_x - 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x + 0.2f)] != '1' &&
		game->map[(int)(new_y - 0.2f)][(int)(new_x - 0.2f)] != '1'
	)
	{
		game->pos_x = new_x;
		game->pos_y = new_y;
	}
	return (SUCCESS);
}


// int	move_up(t_infra *infra)
// {
// 	infra->data->game.pos_x += 0.2 * infra->data->game.dir_y;
// 	infra->data->game.pos_y += 0.2 * infra->data->game.dir_x;
// 	return (SUCCESS);
// }

// int	move_down(t_infra *infra)
// {
// 	infra->data->game.pos_x -= 0.2 * infra->data->game.dir_y;
// 	infra->data->game.pos_y -= 0.2 * infra->data->game.dir_x;
// 	return (SUCCESS);
// }

// int	move_right(t_infra *infra)
// {
// 	infra->data->game.pos_x += 0.2 * infra->data->game.dir_x;
// 	infra->data->game.pos_y -= 0.2 * infra->data->game.dir_y;
// 	return (SUCCESS);
// }

// int	move_left(t_infra *infra)
// {
// 	infra->data->game.pos_x -= 0.2 * infra->data->game.dir_x;
// 	infra->data->game.pos_y += 0.2 * infra->data->game.dir_y;
// 	return (SUCCESS);
// }

int	move_turn(t_infra *infra, int keycode)
{
	if (keycode == XK_Left)
		infra->data->game.angle -= 0.2;
	if (keycode == XK_Right)
		infra->data->game.angle += 0.2;
	infra->data->game.dir_x = cos (infra->data->game.angle);
	infra->data->game.dir_y = sin (infra->data->game.angle);
	return (SUCCESS);
}
