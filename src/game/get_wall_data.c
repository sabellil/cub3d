/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/21 14:35:27 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

// typedef struct s_dda_data
// {
// 	t_pairf	delta_dist;
// 	t_pairf	side_dist;
// 	t_pairf	offset;
// 	t_pairf	cross;
// 	t_pairf	dir;
// 	int		side;
// }	t_dda_data;

t_hit_info ft_calc_dst_and_side(t_dda_data   data)
{
    t_hit_info  result;

    result.axis_hit = data.axis_wall_hit;
    result.wall_dst = data.side_dist.x - data.delta_dist.x;
	result.cross = data.cross;
    if(data.axis_wall_hit)
        result.wall_dst = data.side_dist.y - data.delta_dist.y;
    return (result);
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


static void	ft_init_dda_data(t_dda_data *d, float alpha, 
        float *current_x, float *current_y)
{
	d->dir.x = cosf(alpha);
	d->dir.y = sinf(alpha);
	d->cross.x = floorf(*current_x);
	d->cross.y = floorf(*current_y);
	d->delta_dist.x = fabsf(1.0f / d->dir.x);
	d->delta_dist.y = fabsf(1.0f / d->dir.y);
	d->offset.x = -1;
	d->offset.y = -1;
	d->side_dist.x = (*current_x - d->cross.x) * d->delta_dist.x;
	d->side_dist.y = (*current_y - d->cross.y) * d->delta_dist.y;
    d->axis_wall_hit = 0;
	if (d->dir.x > 0)
	{
		d->side_dist.x = (d->cross.x + 1 - *current_x) * d->delta_dist.x;
		d->offset.x = 1;
	}
	if (d->dir.y > 0)
	{
		d->side_dist.y = (d->cross.y + 1 - *current_y) * d->delta_dist.y;
		d->offset.y = 1;
	}
}

//get wall data
t_hit_info get_wall_data(t_game_data *game, float alpha, float *current_x, float *current_y)
{
    t_dda_data  d;

    ft_init_dda_data(&d, alpha, current_x, current_y);
    while (ft_is_it_a_wall(game, d.cross.y, d.cross.x) != SUCCESS)
    {
        if (d.side_dist.x < d.side_dist.y)
        {
            d.side_dist.x += d.delta_dist.x;
            d.cross.x += d.offset.x;
            d.axis_wall_hit = 0;
        }
        else
        {
            d.side_dist.y += d.delta_dist.y;
            d.cross.y += d.offset.y;
            d.axis_wall_hit = 1;
        }
    }
    return (ft_calc_dst_and_side(d));
}
