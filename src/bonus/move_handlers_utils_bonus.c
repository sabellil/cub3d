/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:25:44 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/29 18:30:44 by sabellil         ###   ########.fr       */
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
