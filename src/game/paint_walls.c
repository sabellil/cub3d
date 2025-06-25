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

int ft_is_it_a_wall(t_game_data *game, float x, float y)
{
    (void)game;
    x++;
    y++;
    return SUCCESS;
}

float ft_where_is_the_wall_x(t_game_data *game, float alpha, float *current_x, float *current_y)
{
    t_pairf dir;
    t_pairf cross;
    t_pairf dif;

    dir.x = cosf(alpha);
    dir.y = sinf(alpha);
    
    while (1)
    {
        cross.x = floorf(*current_x);
        if (dir.x > 0)
            cross.x += 1;
        dif.x = cross.x - *current_x;
        dif.y = dif.x * (dir.y / dir.x);
        cross.y = *current_y + dif.y;
        *current_x = cross.x;
        *current_y = cross.y;
        if (ft_is_it_a_wall(game, cross.x, cross.y) == SUCCESS)
            return (ft_get_wall_distance(game, cross));
    }
}

//TODO: A check
float ft_where_is_the_wall_y(t_game_data *game, float alpha, float *current_x, float *current_y)
{
    t_pairf dir;
    t_pairf cross;
    t_pairf dif;

    dir.x = cosf(alpha);
    dir.y = sinf(alpha);
    
    while (1)
    {
        cross.y = floorf(*current_y);
        if (dir.y > 0)
            cross.y += 1;
        dif.y = cross.y - *current_y;
        dif.x = dif.y * (dir.x / dir.y);
        cross.x = *current_x + dif.x;
        *current_x = cross.x;
        *current_y = cross.y;
        if (ft_is_it_a_wall(game, cross.x, cross.y) == SUCCESS)
            return (ft_get_wall_distance(game, cross));
    }
}

//TODO replace NULL par IMG Next
int ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float y)
{
    t_pairf     dst;
    t_pairf     player_pos;
    int         color;
    float       dst_wall;
    int         x;

    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;
    dst.x = ft_where_is_the_wall_x(game, alpha_tmp, &player_pos.x, &player_pos.y);
    dst.y = ft_where_is_the_wall_y(game, alpha_tmp, &player_pos.x, &player_pos.y);
    if (dst.x < dst.y)
    {
        dst_wall = dst.x;
        color = 5;
        //color = east_or_west(alpha_tmp);
    }
    else
    {
        dst_wall = dst.y;
        dst_wall++;
        color = 7;
        color++;
        //color = north_or_south(alpha_tmp);
    }
    x = 0;
    while (x <= HEIGHT)
    {
        // if (ft_check_if_wall_to_redo (dst_wall, color, game, x) == SUCCESS)
        //     put_pixel(NULL, color, x, y);
        x++;
        (void)y;
    }
    return SUCCESS;
}

int ft_paint_the_wall(t_game_data *game)
{
    float   delta;
    float   alpha_tmp;
    int     y;

    delta = FOV / WIDTH;
    alpha_tmp = game->angle - (FOV / 2);
    y = 0;

    while (y < WIDTH)
    {
        ft_paint_one_pix_collumn(game, alpha_tmp, y);
        y++;
        alpha_tmp += delta;
    }
    return SUCCESS;
}
