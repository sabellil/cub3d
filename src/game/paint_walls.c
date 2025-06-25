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

float ft_get_wall_distance(t_data_game *game, float x, float y)
{
    float   dx;
    float   dy;
    float  dst;

    dx = x - game->pos_x;
    dy = y - game->pos_y;
    dst = sqrtf(dx * dx + dy * dy);
    return (dst);
}


int ft_paint_one_pix_collumn(t_game_data *game, alpha_tmp)
{
    float   wall_x;
    float   wall_y;
    float   dst;
    int     color;

    wall_x = 0;
    wall_y = 0;
    dst = ft_get_wall_distance(game, wall_x, wall_y);
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
        ft_paint_one_pix_collumn(game, alpha_tmp);
        while (x < HEIGHT)
        {
            if (ft_check_if_wall_to_redo (dst, color, game, x) == SUCCESS)
                pixel_color = color
            x++
        }
        y++;
        alpha_tmp += delta;
    }

    return SUCCESS;
}
