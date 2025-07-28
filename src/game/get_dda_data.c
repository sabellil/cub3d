
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

// typedef struct	s_data_dda 
// {
//     t_pairf 	map_case;
//     t_pairf 	dir;
//     t_pairf 	step;
//     t_pairf 	delta_dist;
//     t_pairf 	wall_dist_on;
// }				t_data_dda;

float   get_delta_dist_from_dir(float dir)
{
    float   result;

    if(dir == 0.0f)
        result = 1e30;
    else
        result = fabsf(1.0f / dir);
    return (result);
}

float   get_step_from_dir(float dir)
{
    float step;

    step = 1;
    if (dir < 0)
        step = -1;
    return(step);
}

float   get_wall_dist(float actual_case, float dir, float map_case, float delta_dist)
{
    float   wall_distance;

    wall_distance = (map_case + 1.0f - actual_case) * delta_dist;
    if (dir < 0)
        wall_distance = (actual_case - map_case) * delta_dist;
    return (wall_distance);
}

t_data_dda init_data_dda(float alpha, float *curr_x, float *curr_y)
{
    t_data_dda dda;

    dda.dir.x = cosf(alpha);
	dda.dir.y = sinf(alpha);
	dda.map_case.x = floorf(*curr_x);
	dda.map_case.y = floorf(*curr_y);
    dda.delta_dist.x = get_delta_dist_from_dir(dda.dir.x);
    dda.delta_dist.y = get_delta_dist_from_dir(dda.dir.y);
    dda.step.x = get_step_from_dir(dda.dir.x);
    dda.step.y = get_step_from_dir(dda.dir.y);
    dda.wall_dist_on.x = get_wall_dist(*curr_x, dda.dir.x, dda.map_case.x,
        dda.delta_dist.x);
    dda.wall_dist_on.y = get_wall_dist(*curr_y, dda.dir.y, dda.map_case.y, dda.delta_dist.y);
    return (dda);
}


	// if (dda.dir.x == 0.0f)
	// 	dda.delta_dist.x = 1e30;
	// else
	// 	dda.delta_dist.x = fabsf(1.0f / dda.dir.x);

	// if (dda.dir.y == 0.0f)
	// 	dda.delta_dist.y = 1e30;
	// else
	// 	dda.delta_dist.y = fabsf(1.0f / dda.dir.y);

	// if (dda.dir.x < 0)
	// {
	// 	dda.step.x = -1;
	// 	dda.wall_dist_on.x = (*curr_x - dda.map_case.x) * dda.delta_dist.x;
	// }
	// else
	// {
	// 	dda.step.x = 1;
	// 	dda.wall_dist_on.x = (dda.map_case.x + 1.0f - *curr_x) * dda.delta_dist.x;
	// }

	// if (dda.dir.y < 0)
	// {
	// 	dda.step.y = -1;
	// 	dda.wall_dist_on.y = (*curr_y - dda.map_case.y) * dda.delta_dist.y;
	// }
	// else
	// {
	// 	dda.step.y = 1;
	// 	dda.wall_dist_on.y = (dda.map_case.y + 1.0f - *curr_y) * dda.delta_dist.y;
	// }
