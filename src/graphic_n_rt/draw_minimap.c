/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:42:21 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/12 12:49:59 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// DESSINER LA MINIMAP ET LE JOUEUR

//void	draw_minimap(t_data *data)//dessine pixel par pixel un carre colore
//on commence a dessiner a partir de la premiere ligne de la map 
//on dessine sur img_nxt - celle qui n'est pas encore affichee
//boucle pour parcourir la hauteur 
	//une boucle parcourant chaque case en fonction de la largeur
			//si 1 alors mur noir
			// sol blanc
			//si espace : blanc 
	//appel draw square
//appel square pour dessiner le joueur en rouge : 
// x position horizontale du joueur * taille du pixel, la meme pour y en vertical
//la taille du carre qui represente le joueur
//la couleur du caree

// void	draw_square()//on dessine chaque pixel du joueur
// {
// 	//boucle pour parcourir les pixels a remplir pour le joueur
// 	// appel put_pixel();//mettre une couleur sur le pixel  x+j (la position horizontal du pixel)
// }
