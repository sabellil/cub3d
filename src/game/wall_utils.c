/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:39:09 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/02 12:38:04 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

int	ft_is_it_a_wall(t_game_data *game, float x, float y)//la position du joueur touche t elle un mur ?
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map_width ||
		map_y < 0 || map_y >= game->map_height)
		return (ERR_PARSE_FAIL);//on est en dehors de la carte
	if (game->map[map_y][map_x] == '1')
		return (SUCCESS);//c'est un mur
	return (FAILURE);//c'est pas un mur
}

//height/ 2.0f = milieu vertical de l'ecran
//wall_height / 2.0f = moitie de la hauteur du mur
//start = pixel du haut du mur (milieu - moitie de la hauteur)
//end = pixel du bas du mur (milieu + moitie de la hauteur)

int	ft_check_if_wall_to_redo(float dst, int color, t_game_data *game, int x)//quelle huateur de mur afficher selon ma position
{
	float	wall_height;
	float	start;
	float	end;
	(void)color;// on applique pas la couleur ici donc jignore
	(void)game;
	if (dst <= 0.0f)//si la distance est nulle ou negatif je dessie pas
		return (0);
	wall_height = (float)HEIGHT / dst;//calcul de la hauteur du mur a lecran
	start = (float)HEIGHT / 2.0f - wall_height / 2.0f;//calcul  ou commence le et finit le mur su rlecran
	end = (float)HEIGHT / 2.0f + wall_height / 2.0f;
	if (x >= (int)start && x <= (int)end)// verif si x envoye est dans la zone du mur
		return (1); //je dessine
	return (0);//je dessine pas car le pixel ne fiat pas partie du mur
}