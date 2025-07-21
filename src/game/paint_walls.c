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


t_dst_side ft_get_dst_side(int side, t_pairf wall_pos)
{
    t_dst_side  result;

    result.side = side;
    result.wall_dst = wall_pos.x;
    if(side)
        result.wall_dst = wall_pos.y;
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

// t_dst_side get_wall_distance_x_y(t_game_data *game, float alpha, float *current_x, float *current_y)
// {
//     t_pairf dir;
//     t_pairf cross;
//     float offset_y; //un seul offset ici ? Sinon faire une t_pair
//     float offset_x;
//     char  side = 0; //Gab ? besoin d'info sur ce truc

//     dir.x = cosf(alpha);
//     dir.y = sinf(alpha);
//     cross.y = floorf(*current_y);
//     cross.x = floorf(*current_x);

//     float delta_dist_x = fabsf(1 / dir.x);
//     float delta_dist_y = fabsf(1 / dir.y);
//     float side_dist_x = (*current_x - cross.x) * delta_dist_x;
//     float side_dist_y = (*current_y - cross.y) * delta_dist_y;
//     offset_x = -1;
//     offset_y = -1;
//     if (dir.x > 0)
//     {
//         side_dist_x  = (cross.x + 1  - *current_x) * delta_dist_x;
//         offset_x = 1;
//     }
//     if (dir.y > 0)
//     {
//         side_dist_y  = (cross.y + 1  - *current_y) * delta_dist_y;
//         offset_y = 1;
//     }
//     while (ft_is_it_a_wall(game, cross.y, cross.x) != SUCCESS)
//     {
//         if (side_dist_x < side_dist_y)
//         {
//             side_dist_x += delta_dist_x;
//             cross.x += offset_x;
//             side = 0;
//         }
//         else
//         {
//             side_dist_y += delta_dist_y;
//             cross.y += offset_y;
//             side = 1;
//         }
//     }

//     return (ft_get_dst_side(side, (t_pairf){
//         .x = (side_dist_x - delta_dist_x),
//         .y = (side_dist_y - delta_dist_y)
//     }));
// }


t_dst_side	get_wall_distance_x_y(t_game_data *game, float alpha, float *current_x, float *current_y)
{
	t_pairf	dir;
	t_pairf	cross;
	t_pairf	step;
	t_pairf	side_dist;
	t_pairf	delta_dist;
	int		side;
	t_pairf	hit;
	float	wall_dst;

	dir.x = cosf(alpha);
	dir.y = sinf(alpha);

	cross.x = floorf(*current_x);
	cross.y = floorf(*current_y);

	if (dir.x == 0.0f)
		delta_dist.x = 1e30;
	else
		delta_dist.x = fabsf(1.0f / dir.x);

	if (dir.y == 0.0f)
		delta_dist.y = 1e30;
	else
		delta_dist.y = fabsf(1.0f / dir.y);

	if (dir.x < 0)
	{
		step.x = -1;
		side_dist.x = (*current_x - cross.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = (cross.x + 1.0f - *current_x) * delta_dist.x;
	}

	if (dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (*current_y - cross.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		side_dist.y = (cross.y + 1.0f - *current_y) * delta_dist.y;
	}

	while (ft_is_it_a_wall(game, cross.y, cross.x) != SUCCESS)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			cross.x += step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			cross.y += step.y;
			side = 1;
		}
	}

	if (side == 0)
	{
		wall_dst = side_dist.x - delta_dist.x;
		hit.x = cross.x;
		hit.y = *current_y + wall_dst * dir.y;
	}
	else
	{
		wall_dst = side_dist.y - delta_dist.y;
		hit.y = cross.y;
		hit.x = *current_x + wall_dst * dir.x;
	}

	t_dst_side result;
	result.side = side;
	result.wall_dst = wall_dst;
	result.hit = hit;
	return (result);
}

t_asset *get_texture_by_oriantation(t_game_data *game, int side, float alpha) {
    if (side) {
        if (sinf(alpha) >= 0)
            return &game->tex_ea;
        return &game->tex_so;
    }
    if (cosf(alpha) >= 0)
        return &game->tex_we;
    return &game->tex_no;
}


int	ft_check_if_wall_to_redo(float dst, int color, t_game_data *game, int x)//quelle huateur de mur afficher selon ma position
{
	float	wall_height;
    (void) x;
	(void)color;//on applique pas la couleur ici donc jignore
	(void)game;
	wall_height = (float)HEIGHT / dst;//calcul de la hauteur du mur a lecran
	return (FAILURE);//je dessine pas car le pixel ne fiat pas partie du mur
}

// static float	get_start_of_wall(const t_pairf *player_pos, t_dst_side *dst_side, float alpha)
// {
// 	float	wall_x;

// 	if (dst_side->side == 0)
// 		wall_x = player_pos->y + dst_side->wall_dst
// 			* sinf(alpha);
// 	else
// 		wall_x = player_pos->x + dst_side->wall_dst
// 			*  cosf(alpha);
    
// 	return (fabsf(wall_x - floorf(wall_x)));
// }

float	ft_min(size_t n, size_t n2)
{
	if (n < n2)
		return (n);
	return (n2);
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


void    draw_wall(t_game_data *game, t_param_w *params, int start, int end) {
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