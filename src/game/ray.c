/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:32:04 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/16 13:46:56 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
/* - Une boucle while qui passe en revue tous les x (en vertical)
- 
Le rayon demarre la position du joueur posX, posY

*/
// 1. Lancer un rayon 
// 2. Utiliser DDA pour voir la ou on tape sur un mur
// 3. Calcul de la distance au mur
// 4. Calculer la hauteur de la ligne verticale a afficher
// 5. Faire la meme pour chaque colonne a l'ecran 