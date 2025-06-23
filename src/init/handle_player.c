/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:38 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/23 13:30:41 by mairivie         ###   ########.fr       */
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
		return (ERR_PARSE_FAIL);
	game->pos_x = x + 0.5;//placer le joueur au milieu de la case colonne
	game->pos_y = y + 0.5;//ligne
	game->player_found = 1; 
	if (c == 'N')
		//game->dir_y = -1;//vers le haut de l'ecran
		game->angle =
	else if (c == 'S')
		game->dir_y = 1;//vers le bas
		game->angle =
	else if (c == 'E')
		game->dir_x = 1;//vers la droite
		game->angle =
	else if (c == 'W')
		game->dir_x = -1;// vers la gauche
		game->angle =
	game->dir_x = 0;//dir a recalculer a partir de l'angle avec cos/sin
	game->dir_y = 0;
	game->map[y][x] = '0';//remplacer la lettre du joueur dans la map par case vide pour pas la gerer ocmme mur dans la suite du jeu
	return (SUCCESS);
}
