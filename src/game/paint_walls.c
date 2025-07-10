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

float ft_get_wall_distance(t_game_data *game, t_pairf wall_pos)
{
    float   dx;
    float   dy;
    float  dst;

    dx = wall_pos.x - game->pos_x;
    dy = wall_pos.y - game->pos_y;
    dst = sqrtf(dx * dx + dy * dy);
    return (dst);
}

int	ft_is_it_a_wall(t_game_data *game, float x, float y)
{
	int		map_x;
	int		map_y;
	char	cell;

    map_x = floorf(x);
    map_y = floorf(y);
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

float ft_where_is_the_wall_x(t_game_data *game, float alpha, float *current_x, float *current_y)
{
    t_pairf dir;
    t_pairf cross;
    t_pairf dif;
    float offset_x;

    offset_x = 1.0f;
    dir.x = cosf(alpha);
    dir.y = sinf(alpha);
    if (dir.x < 0)
        offset_x = -1.0f;
    cross.y = floorf(*current_y);
    cross.x = floorf(*current_x);
    
    while (ft_is_it_a_wall(game, cross.x + offset_x, cross.y) != SUCCESS)
    {
        cross.x += offset_x;
        // if (dir.x > 0)
        //     cross.x += 1.0f;
        dif.x = fabsf(cross.x - *current_x);
        dif.y = dif.x * (dir.y / dir.x);
        cross.y = *current_y + dif.y;
    }
    return (ft_get_wall_distance(game, cross));
}

//TODO: A check
float ft_where_is_the_wall_y(t_game_data *game, float alpha, float *current_x, float *current_y)
{
    t_pairf dir;
    t_pairf cross;
    t_pairf dif;
    float offset_y;

    offset_y = 1.0f;
    dir.x = cosf(alpha);
    dir.y = sinf(alpha);
    if (dir.y < 0)
        offset_y = -1.0f;
    cross.y = floorf(*current_y);
    cross.x = floorf(*current_x);
    
    while (ft_is_it_a_wall(game, cross.x, cross.y + offset_y) != SUCCESS)
    {
        cross.y += offset_y;
        // if (dir.y > 0)
        //     cross.y += 1.0f;
        dif.y = fabsf(cross.y - *current_y);
        dif.x = dif.y * (dir.x / dir.y);
        cross.x = *current_x + dif.x;
    }
    return (ft_get_wall_distance(game, cross));
}

int	ft_check_if_wall_to_redo(float dst, int color, t_game_data *game, int y)//quelle huateur de mur afficher selon ma position
{
	float	wall_height;
	float	start;
	float	end;
	(void)color;//on applique pas la couleur ici donc jignore
	(void)game;
	wall_height = (float)HEIGHT / dst;//calcul de la hauteur du mur a lecran
	start = (float)HEIGHT / 2.0f - wall_height / 2.0f;//calcul  ou commence le et finit le mur su rlecran
	end = (float)HEIGHT / 2.0f + wall_height / 2.0f;
	if (y >= start && y <= end)//verif si x envoye est dans la zone du mur
		return (SUCCESS);//je dessine
	return (FAILURE);//je dessine pas car le pixel ne fiat pas partie du mur
}

int ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float x)
{
    t_pairf     dst;
    t_pairf     player_pos;
    int         color;
    float       dst_wall;
    float       y;

    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;
    dst.x = player_pos.x;
    dst.y = player_pos.y;
    dst.x = ft_where_is_the_wall_x(game, alpha_tmp, &player_pos.x, &player_pos.y);
    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;
    dst.y = ft_where_is_the_wall_y(game, alpha_tmp, &player_pos.x, &player_pos.y);
    if (dst.x < dst.y)
    {
        dst_wall = dst.x;
        color = 1703705; //vert
        if (cosf(alpha_tmp) >= 0)
            color = 16435200; //jaune moche
        //color = east_or_west(alpha_tmp);
    }
    else
    {
        dst_wall = dst.y;
        color = 1645055; //blue
        if (sinf(alpha_tmp) >= 0)
            color = 16416000; //orange
        //color = north_or_south(alpha_tmp);
    }
    y = 0;
    while (y < HEIGHT)
    {
        if (!ft_check_if_wall_to_redo (dst_wall, color, game, y))
        put_pixel(game->data->infra.img_nxt, color, x, y);
        y++;
    }
    return SUCCESS;
}

int ft_paint_the_wall(t_game_data *game)
{
    float   delta;
    float   alpha_tmp;
    float     x;

    delta = FOV / WIDTH;
    alpha_tmp = game->angle - (FOV / 2);
    x = 0;
    while (x < WIDTH)
    {
        if (ft_paint_one_pix_collumn(game, alpha_tmp, x) == FAILURE)
            return (FAILURE);
        x++;
        alpha_tmp = alpha_tmp + delta;
    }
    return SUCCESS;
}
