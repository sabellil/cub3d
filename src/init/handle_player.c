/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:38 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/18 14:46:07 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	is_valid_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	count_and_set_player(t_game_data *game, int y, int x, char c)
{
	if (game->player_found)
		return (ERR_PARSE_FAIL);
	game->pos_x = y + 0.5; // ligne
	game->pos_y = x + 0.5; // colonne
	game->player_found = 1;
	if (c == 'N')
		game->angle_fov = -PI / 2;
	else if (c == 'S')
		game->angle_fov = PI / 2;
	else if (c == 'E')
		game->angle_fov = 0;
	else if (c == 'W')
		game->angle_fov = PI;
	game->dir_x = cos(game->angle_fov);
	game->dir_y = sin(game->angle_fov);
	game->map[y][x] = '0';
	return (SUCCESS);
}
