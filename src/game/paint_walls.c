/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/24 16:37:47 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"


float ft_get_wall_distance(t_game_data *game, int side, t_pairf wall_pos)
{
    (void) game;
    //TODO rework this fonction
    if(side)
        return (wall_pos.y);
    return (wall_pos.x);
}

int	ft_is_it_a_wall(t_game_data *game, float y, float x)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = round(x);
	map_y = round(y);
	if (map_y < 0 || map_y >= game->map_height || map_x < 0
		|| map_x >= game->map_width)
		return (SUCCESS);
	cell = game->map[map_y][map_x];
	if (cell == '1' || cell == ' ')
		return (SUCCESS);
	else
		return (FAILURE);
}
//TODO oh l'enfer que ca va etre a refacto, faut envoyer une paire avec le currentx et current y
float get_wall_distance_x_y(t_game_data *game, float alpha, int *color, float *current_x, float *current_y)
{
    t_pairf dir;
    t_pairf cross;
    float offset_y; //un seul offset ici ? Sinon faire une t_pair
    float offset_x;
    char  side = 0; //Gab ? besoin d'info sur ce truc

    dir.x = cosf(alpha);
    dir.y = sinf(alpha);
    cross.y = floorf(*current_y);
    cross.x = floorf(*current_x);

    float delta_dist_x = fabsf(1 / dir.x);
    float delta_dist_y = fabsf(1 / dir.y);
    float side_dist_x = (*current_x - cross.x) * delta_dist_x;
    float side_dist_y = (*current_y - cross.y) * delta_dist_y;
    offset_x = -1;
    offset_y = -1;
    if (dir.x > 0)
    {
        side_dist_x  = (cross.x + 1  - *current_x) * delta_dist_x;
        offset_x = 1;
    }
    if (dir.y > 0)
    {
        side_dist_y  = (cross.y + 1  - *current_y) * delta_dist_y;
        offset_y = 1;
    }
    while (ft_is_it_a_wall(game, cross.y, cross.x) != SUCCESS)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            cross.x += offset_x;
            *color = GREEN;
            if (cosf(alpha) >= 0)
                *color = YELLOW;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            cross.y += offset_y;
            *color = BLUE;
            if (sinf(alpha) >= 0)
                *color = ORANGE;
            side = 1;
        }
    }
    //TODOcidessous faire un ft dediee
    return (ft_get_wall_distance(game, side, (t_pairf){
        .x = (side_dist_x - delta_dist_x),
        .y = (side_dist_y - delta_dist_y)
    }));
}


int	ft_check_if_wall_to_redo(float dst, int color, t_game_data *game, int x)//quelle huateur de mur afficher selon ma position
{
	float	wall_height;
    (void) x;
	(void)color;//on applique pas la couleur ici donc jignore
	(void)game;
	wall_height = (float)HEIGHT / dst;//calcul de la hauteur du mur a lecran
	return (FAILURE);//je dessine pas car le pixel ne fiat pas partie du mur
    //TODOrename et reorga cette ft: elle donne la hauteur du mur a dessiner + modifier ici pour avoir la hauteur max du mur un peu plus petite que la hauteur dela fenetre
}

int ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float y)
{
    t_pairf     player_pos;
    int         color;
    float       dst_wall;
	float	start;
	float	end;

    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;
    color = 1703705;
    dst_wall = get_wall_distance_x_y(game, alpha_tmp, &color, &player_pos.y, &player_pos.x);
    dst_wall *= cos(alpha_tmp - game->angle); //correction du fisheye
    if (dst_wall < 0.01)
		dst_wall = 0.01;
    int wall_height = (float)HEIGHT / dst_wall;//calcul de la hauteur du mur a lecran
	start = (float)HEIGHT / 2.0f - wall_height / 2.0f;//calcul  ou commence le et finit le mur su rlecran
	end = (float)HEIGHT / 2.0f + wall_height / 2.0f;
    while (start < end)
    {
        put_pixel(game->data->infra.img_nxt, color, y, start);
        start++;
    }
    return SUCCESS;
}

int ft_paint_the_wall(t_game_data *game)
{
    float   delta;
    float   alpha_tmp;
    float     y;

    delta = FOV / WIDTH;
    alpha_tmp = game->angle - (FOV / 2);
    y = 0;
    while (y < 1280.0f)
    {
        if (ft_paint_one_pix_collumn(game, alpha_tmp, y) == FAILURE)
            return (FAILURE);
        y++;
        alpha_tmp = alpha_tmp + delta;
    }
    return SUCCESS;
}
