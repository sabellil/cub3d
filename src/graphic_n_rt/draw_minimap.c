/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:42:21 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/13 10:37:20 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_minimap(t_data *data)
{
	int		tile_size;
	int		y;
	int		x;
	int		color;
	char	current_case;
	t_img	*img;

	img = data->infra.img_nxt;
	tile_size = 10;
	y = 0;
	while (y < data->game.map_height)
	{
		x = 0;
		while (x < data->game.map_width)
		{
			current_case = data->game.map[y][x];
			if (current_case == '1')
				color = 0x0000;
			if (current_case == '0')
				color = 0xffff;
			else
				color = 0x0000;
			draw_square(img, data->game.pos_x * tile_size, data->game.pos_y * tile_size, tile_size, color);
			x++;
		}
		y++;
	}
	draw_square(img, (int)(data->game.pos_x * tile_size), (int)(data->game.pos_y * tile_size), 4, 0xFF0000);
}

void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, color, x + j, y + i);
			j++;
		}
		i++;
	}
}
// DESSINER LA MINIMAP ET LE JOUEUR

//void	draw_minimap(t_data *data)//dessine pixel par pixel un carre colore
//on commence a dessiner a partir de la premiere ligne de la map 
//on dessine sur img_nxt - celle qui n'est pas encore affichee
//boucle pour parcourir la hauteur 
	//une boucle parcourant chaque case en fonction de la largeur
			//si 1 alors mur noir
			// si 0 sol blanc
			//si espace : noir 
	//appel draw square
//appel draw square pour dessiner le joueur en rouge : 
// x position horizontale du joueur * taille du pixel, la meme pour y en vertical
//la taille du carre qui represente le joueur
//la couleur du caree

// void	draw_square()//on dessine chaque pixel du joueur
// {
// 	//boucle pour parcourir les pixels a remplir pour le joueur
// 	// appel put_pixel();//mettre une couleur sur le pixel  x+j (la position horizontal du pixel)
// }
