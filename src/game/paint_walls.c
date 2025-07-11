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
	{
		return (SUCCESS);
	}
	else
	{
		return (FAILURE);
	}
}

float get_wall_distance_x_y(t_game_data *game, float alpha, int *color, float *current_x, float *current_y)
{
    t_pairf dir;
    t_pairf cross;
    float offset_y;
    float offset_x;
    char  side = 0;

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
            *color = 1703705; // vert
            if (cosf(alpha) >= 0)
                *color = 16435200; // jaune moche
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            cross.y += offset_y;
            *color = 1645055; // bleu
            if (sinf(alpha) >= 0)
                *color = 16416000; // orange
            side = 1;
        }
    }

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
	// if (dst <= 0.0f)//si la distance est nulle ou negatif je dessie pas
	// 	return (FAILURE);
	wall_height = (float)HEIGHT / dst;//calcul de la hauteur du mur a lecran
	return (FAILURE);//je dessine pas car le pixel ne fiat pas partie du mur
}

int ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float y)
{
    t_pairf     player_pos;
    int         color;
    float       dst_wall;
    // float       x;
	float	start;
	float	end;

    //printf("pos.x %f y:%f\n", game->pos_x, y);
    player_pos.x = game->pos_x;
    //printf("player_pos.x %f \n", player_pos.x);
    player_pos.y = game->pos_y;
    //     //printf("player_pos.x = %f  player_pos.y = %f\n", player_pos.x, player_pos.y);
    // dst.x = ft_where_is_the_wall_x(game, alpha_tmp, &player_pos.x, &player_pos.y);
    //     printf("dst.x = %f\n", dst.x);
    //  player_pos.x = game->pos_x;
    //  player_pos.y = game->pos_y;
    color = 1703705;
     dst_wall = get_wall_distance_x_y(game, alpha_tmp, &color, &player_pos.y, &player_pos.x);

     dst_wall *= cos(alpha_tmp - game->angle);
    if (dst_wall < 0.01)
		dst_wall = 0.01;
    int wall_height = (float)HEIGHT / dst_wall;//calcul de la hauteur du mur a lecran
	start = (float)HEIGHT / 2.0f - wall_height / 2.0f;//calcul  ou commence le et finit le mur su rlecran
	end = (float)HEIGHT / 2.0f + wall_height / 2.0f;
    while (start < end)
    {
        // if (!ft_check_if_wall_to_redo (dst_wall, color, game, x))
        // printf("dst_wall = %f x = %f et y = %f \n",dst_wall, x, y);
        put_pixel(game->data->infra.img_nxt, color, y, start);
        start++;
    }
    //(void)alpha_tmp;
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
        //printf("y = %f alpha = %f delta = %f\n", y, alpha_tmp, delta);
        if (ft_paint_one_pix_collumn(game, alpha_tmp, y) == FAILURE)
            return (FAILURE);
        y++;
        alpha_tmp = alpha_tmp + delta;
    }
    return SUCCESS;
}
