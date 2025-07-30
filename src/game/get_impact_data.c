/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_impact_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:45:49 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/30 14:44:43 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

// typedef struct s_impact_data 
// {
// 	int 	axis_hit;
// 	float	wall_dst;
// 	t_pairf	hit;
// }			t_impact_data;

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

//TODO pas besoin de game non ?
t_impact_data	get_impact_data_with_dda(t_game_data *game, 
	float alpha, float *curr_x, float *curr_y)
{
    t_data_dda d;
	t_impact_data impact;

	ft_bzero(&impact, sizeof(t_impact_data));
    d = init_data_dda(alpha, curr_x, curr_y);
	//on pourrait avoir une fonction find_wall_hit_axis
	while (ft_is_it_a_wall(game, d.map_case.y, d.map_case.x) != SUCCESS)
	{
		if (d.wall_dist_on.x < d.wall_dist_on.y)
		{
			d.wall_dist_on.x += d.delta_dist.x;
			d.map_case.x += d.step.x;
			impact.axis_hit = HORIZ_X;
		}
		else
		{
			d.wall_dist_on.y += d.delta_dist.y;
			d.map_case.y += d.step.y;
			impact.axis_hit = VERTI_Y;
		}
	}
	fill_impact_data(d, &impact, curr_x, curr_y);
	return (impact);
}

void fill_impact_data(t_data_dda d, t_impact_data *impact, float *curr_x, float *curr_y)
{
	if (impact->axis_hit == HORIZ_X)
	{
		impact->wall_dst = d.wall_dist_on.x - d.delta_dist.x;
		impact->hit.x = d.map_case.x;
		impact->hit.y = *curr_y + impact->wall_dst * d.dir.y;
	}
	else
	{
		impact->wall_dst = d.wall_dist_on.y - d.delta_dist.y;
		impact->hit.y = d.map_case.y;
		impact->hit.x = *curr_x + impact->wall_dst * d.dir.x;
	}
}
