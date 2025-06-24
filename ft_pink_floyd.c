/* 

1/
Modif fonction d’init existante pour que 

INIT l'angle directeur
Valeur d'init de l'angle directeur SARAAAA
E = 0
N = ½ PI rad
O = 1 PI rad
S = 1 ½ PI rad

Puis initi valeur de dir x et dir y
Dir x = cos (alpha)
Dir y = sin (alpha)

[...] au dessus SARA / En dessous MADDY

modif fonction de déplacement pour que avancer/reculer 
sur l'axe des x : x +/-= 0.2 * dirx et y +/-= 0.2 diry
sur l'axe des y : x +/-= 0.2 * diry et y +/-= 0.2 dirx

[...]

modif fonction de rotation
fleche droite --> diminutuion de l'angle
fleche gauche <-- augmentation de l'angle
(NB a revoir tete froide doute ici, peut-être pas neccessaire a chaque tour)
verif que l'angle est tjr dans les bornes [0 - 2PI]
Si non, ajuster 
(si ca doit depasser 2PI ca devient 0 et inversement
si ça doit tomber sous 0 ça devient 2PI)

-----------------
[...]
-----------------

Projet Pink Floyd -THE WALL
---------

Int ft_paint_the_wall(t_game *data) MADDY

Int y = 1 (premiere colonne de pixel)
Float delta = FOV / Width => variation d'angle
Float alpha_tmp = alpha - FOV/2 => angle temporaire

While (y < width)
{
    posx_wall = ft_where_is_the_wall_x (*game, alpha_tmp) MADDY a reformuler (un seul appel donc des pointeurs)
    posy_wall = ft_where_is_the_wall_y (*game, alpha_tmp)
	Dst = calcul_dst (posx_wall, posy_wall) => calcul a partir de x et y du mur
	Color = ft_color_of_the_wall (*game, posx_wall, posy_wall)
	
    X = 0 (remise a zero)
	While (x <= height)
    {
        if (ft_check_if_wall_to_redo (dst, color, game, x)) == yes
            pixel_color = color
        x++
    }
    y++
    alpha_tmp =+ delta
}

ft_where_is_the_wall (*game, alpha_tmp)
{
float dst = 0;
float dirx_tmp = cos alpha_tmp
float diry_tmp = sin alpha_tmp

while (dst == 0 ou x et y sont tjr dans la carte) 
NB tete froide=> probablement pas necessaire comme on check systematiquement que la map est fermée;

[tambouille mathemagique pour avoir successivement 
toutes les paires de coorodonéés x+y ou la droite de l'angle croise un bord de case]

envoie de ces paires de coordonées dans une fonction qui regarde si on tombe sur  un mur ou pas
int ft_is_it_a_wall(t_game_data *game, float x, float y) SARAAAAA
{return SUCCESS si c'est un wall}

si oui : save de ces coordonées, retour ft_paint_the_wall
sinon : on passe a la paire de coordonés suivante

}


int ft_check_if_wall_to_redo (dst, color, game) SARA
{
int wall_height

(proportionalite si dst = 1 (= collé au mur) => height==90% hauteur totale (0.9 * HEIGHT)
    plus dst est grand, + wall_height est petit          
    wall_height = height / dst)

if x est entre (Height/2 + wall_height/2) et (Height/2 - wall_height/2)
=> return YES


}
 

*/
