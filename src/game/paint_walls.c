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

//TODO si time, templacer current x et current y par une tpairf player_pos
t_dst_side	get_wall_distance_x_y(t_game_data *game, float alpha, float *current_x, float *current_y)
{
    t_data_dda d;

    d = init_data_dda(alpha, current_x, current_y);
    //2emme structure
	int		axis_hit = 0; //axis_hit + define vertical_y && horizontal_x
	t_pairf	hit;
	float	wall_dst;

	while (ft_is_it_a_wall(game, d.map_case.y, d.map_case.x) != SUCCESS)
	{
		if (d.wall_dist_on.x < d.wall_dist_on.y)
		{
			d.wall_dist_on.x += d.delta_dist.x;
			d.map_case.x += d.step.x;
			axis_hit = 0;
		}
		else
		{
			d.wall_dist_on.y += d.delta_dist.y;
			d.map_case.y += d.step.y;
			axis_hit = 1;
		}
	}

	if (axis_hit == 0)
	{
		wall_dst = d.wall_dist_on.x - d.delta_dist.x;
		hit.x = d.map_case.x;
		hit.y = *current_y + wall_dst * d.dir.y;
	}
	else
	{
		wall_dst = d.wall_dist_on.y - d.delta_dist.y;
		hit.y = d.map_case.y;
		hit.x = *current_x + wall_dst * d.dir.x;
	}

	t_dst_side result;
	result.side = axis_hit;
	result.wall_dst = wall_dst;
	result.hit = hit;
	return (result);
}

t_asset *get_texture_by_oriantation(t_game_data *game, int side, float alpha) 
{
    if (side) {
        if (sinf(alpha) >= 0)
            return &game->tex_ea;
        return &game->tex_we;
    }
    if (cosf(alpha) >= 0)
        return &game->tex_so;
    return &game->tex_no;
}

unsigned int	get_pixel_from_texture(t_asset *texture, int x, int y)
{
	char	*pixel_address;

	if (!texture || !texture->addr)
		return (0);
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel_address = texture->addr + (y * texture->line_len) + (x
			* (texture->bpp / 8));
	return (*(unsigned int *)pixel_address);
}

void    draw_wall(t_game_data *game, t_param_w *params, int start, int end) 
{
    unsigned int color;
	float			tex_pos;
	float			step;


    step = 1.0f * params->texture->height / (int)params->dst_side.wall_dst;
    tex_pos = (start - HEIGHT / 2 + params->dst_side.wall_dst / 2) * step;
    // params->texture_pos = ft_min(params->texture->width, params->texture_x * params->texture->width) /*(TEXTURE_SIZE)*/;

    params->texture_pos = (int)params->texture_x;   
    if (params->dst_side.side == 0 && cosf(params->alpha) > 0)
        params->texture_pos = params->texture->width - params->texture_pos - 1;
    else if (params->dst_side.side  == 1 && sinf(params->alpha) < 0)
        params->texture_pos = params->texture->width - params->texture_pos - 1;
    while (start < end)
    {
		int tx = params->texture_pos;
        int ty = (int)tex_pos & (params->texture->height - 1);
        color = get_pixel_from_texture(params->texture, tx, ty);
        if (color == 0)
            color = 0xFF00FF; // magenta pour repérer le problème
        put_pixel(game->data->infra.img_nxt, color, params->y, start);
        tex_pos += step;
        ++start;
    }
}

void   draw_vertical_line_with_texture(t_game_data *game, t_param_w params)
 {
    float	start;
	float	end;

    params.dst_side.wall_dst = (float)HEIGHT / params.dst_side.wall_dst; //calcul de la hauteur du mur a lecran
    start = ((float)HEIGHT / 2.0f) - (params.dst_side.wall_dst / 2.0f);//calcul  ou commence le et finit le mur su rlecran
    end = ((float)HEIGHT / 2.0f) + (params.dst_side.wall_dst  / 2.0f);
    draw_wall(game, &params, start, end);
}

int	ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float y)
{
	t_pairf		player_pos;
	t_dst_side	dst_side;
	float		wall_x;
	int			texture_x;
	t_asset		*texture;

	player_pos.x = game->pos_x;
	player_pos.y = game->pos_y;

	dst_side = get_wall_distance_x_y(game, alpha_tmp, &player_pos.y, &player_pos.x);

	dst_side.wall_dst *= cosf(alpha_tmp - game->angle);
	if (dst_side.wall_dst < 0.01f)
		dst_side.wall_dst = 0.01f;

	if (dst_side.side == 0)
		wall_x = dst_side.hit.y;
	else
		wall_x = dst_side.hit.x;
	wall_x -= floorf(wall_x);

	texture = get_texture_by_oriantation(game, dst_side.side, alpha_tmp);
	if (!texture || !texture->addr)
	{
		printf("NULL texture !\n");
		return (FAILURE);
	}

	texture_x = (int)(wall_x * (float)texture->width);

	if (dst_side.side == 0 && cosf(alpha_tmp) > 0.0f)
		texture_x = texture->width - texture_x - 1;
	if (dst_side.side == 1 && sinf(alpha_tmp) < 0.0f)
		texture_x = texture->width - texture_x - 1;

	if (texture_x < 0 || texture_x >= texture->width)
	{
		printf("BAD texture_x: %d / texture->width: %d\n", texture_x, texture->width);
		return (FAILURE);
	}

	draw_vertical_line_with_texture(game, (t_param_w){
		.dst_side = dst_side,
		.texture = texture,
		.texture_x = texture_x,
		.texture_pos = 0.0f,
		.y = y,
		.alpha = alpha_tmp
	});
	return (SUCCESS);
}

