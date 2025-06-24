/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:39:09 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/24 15:08:07 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

int	ft_is_it_a_wall(t_game_data *game, float x, float y)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= game->map_height || map_x < 0
		|| map_x >= game->map_width)
		return (ERR_PARSE_FAIL);
	cell = game->map[map_y][map_x];
	if (cell == '1' || cell == ' ')
	{
		// printf("C'EST UN MUR\n");
		return (SUCCESS);
	}
	else
	{
		// printf("ce n'est PAS un mur\n");
		return (FAILURE);
	}
}

// int ft_check_if_wall_to_redo (dst, color, game) 
// {
    
// }


// int ft_check_if_wall_to_redo (dst, color, game) SARA
// {
// int wall_height

// (proportionalite si dst = 1 (= collé au mur) => height==90% hauteur totale (0.9 * HEIGHT)
//     plus dst est grand, + wall_height est petit          
//     wall_height = height / dst)

// if x est entre (Height/2 + wall_height/2) et (Height/2 - wall_height/2)
// => return YES
