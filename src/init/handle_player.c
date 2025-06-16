/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:38 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/16 11:44:25 by sabellil         ###   ########.fr       */
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
	game->dir_x = 0;//direction remis a 0
	game->dir_y = 0;
	game->player_found = 1; 
	if (c == 'N')
		game->dir_y = -1;//vers le haut de l'ecran
	else if (c == 'S')
		game->dir_y = 1;//vers le bas
	else if (c == 'E')
		game->dir_x = 1;//vers la droite
	else if (c == 'W')
		game->dir_x = -1;// vers la gauche
	game->spawn_dir = c;
	game->map[y][x] = '0';//remplacer la lettre du joueur dans la map par case vide pour pas la gerer ocmme mur dans la suite du jeu
	return (SUCCESS);
}
