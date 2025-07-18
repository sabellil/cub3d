/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:38 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/15 16:58:34 by sabellil         ###   ########.fr       */
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
		game->angle = -PI / 2;
	else if (c == 'S')
		game->angle = PI / 2;
	else if (c == 'E')
		game->angle = 0;
	else if (c == 'W')
		game->angle = PI;
	game->dir_x = cos(game->angle);
	game->dir_y = sin(game->angle);
	//printf("dir_x = %f - dir_y = %f \n", game->dir_x, game->dir_y);
	game->map[y][x] = '0';
	return (SUCCESS);
}
