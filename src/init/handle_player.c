/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:38 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/09 13:03:33 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	is_valid_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	count_and_set_player(t_game_data *game, int y, int x, char c)
{
	if (game->player_found)
	{
printf("Plus d'un joueur trouvé ! Coord: y=%d, x=%d, char=%c\n", y, x, c);
		return (ft_handle_error(ERR_PARSE_FAIL));
	}
	game->pos_x = x + 0.5;
	game->pos_y = y + 0.5;
	game->dir_x = 0;
	game->dir_y = 0;
	game->player_found = 1;
	if (c == 'N')
		game->dir_y = -1;
	else if (c == 'S')
		game->dir_y = 1;
	else if (c == 'E')
		game->dir_x = 1;
	else if (c == 'W')
		game->dir_x = -1;
	game->map[y][x] = '0';
	return (SUCCESS);
}
