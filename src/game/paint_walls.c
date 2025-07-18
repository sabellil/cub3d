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

t_asset *get_wall_texture(t_game_data *game, int wall_axis, float ray_angle) 
{
    if (wall_axis == Y_AXIS ) 
    {
        if (sinf(ray_angle) <= 0)
            return &game->tex_so;
        return &game->tex_no;
    }
    if (cosf(ray_angle) <= 0)
        return &game->tex_ea;
    return &game->tex_we;
}

static float	get_offset_texture(const t_pairf *player_pos, t_hit_info *hit_info, float alpha)
{
	float	hit_point;
    float   offset_texture;

	if (hit_info->axis_hit == X_AXIS)
		hit_point = player_pos->y + (hit_info->wall_dst * sinf(alpha));
	else
		hit_point = player_pos->x + (hit_info->wall_dst * cosf(alpha));
    offset_texture = fabsf(hit_point - floorf(hit_point));

	return (offset_texture);
}

size_t	ft_min(size_t n, size_t n2)
{
	if (n < n2)
		return (n);
	return (n2);
}

unsigned int	get_pixel_from_texture(t_asset *texture, int x, int y)
{
	char	        *pixel_address;
    unsigned int    color;

	if (!texture || !texture->addr)
		return (0); //FAILURE
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0); //FAILURE 
	pixel_address = texture->addr + (y * texture->line_len) + (x
			* (texture->bpp / 8));
    color = *(unsigned int*)pixel_address;
	return (color);
}


void    draw_wall(t_game_data *game, t_wall_slice_info *wall_slice_info, int start, int end) 
{
    unsigned int    color;
	float			tex_pos;
	float			step;


    step = 1.0f * wall_slice_info->texture->height / wall_slice_info->wall_heigth;
    tex_pos = (start - HEIGHT / 2 + wall_slice_info->wall_heigth / 2) * step;
    wall_slice_info->texture_pos = ft_min(wall_slice_info->texture->width, wall_slice_info->offset_x * wall_slice_info->texture->width) /*(TEXTURE_SIZE)*/;
    
    if (wall_slice_info->axis_wall_hit == 0 && cosf(wall_slice_info->angle) > 0)
        wall_slice_info->texture_pos = wall_slice_info->texture->width - wall_slice_info->texture_pos - 1;
    else if (wall_slice_info->axis_wall_hit  == 1 && sinf(wall_slice_info->angle) < 0)
        wall_slice_info->texture_pos = wall_slice_info->texture->width - wall_slice_info->texture_pos - 1;
    
    while (start < end)
    {
		color = get_pixel_from_texture(wall_slice_info->texture, wall_slice_info->texture_pos,
				((int)tex_pos & (wall_slice_info->texture->height - 1)));
        // check le succes de l'operation non ? ou juste on se dit aue c'est un pix noir ?
        put_pixel(game->data->infra.img_nxt, color, wall_slice_info->y, start);
        tex_pos += step;
        ++start;
    }
}

void   draw_vertical_line_with_texture(t_game_data *game, t_wall_slice_info wall_slice_info)
{
    int	start;
	int	end;

    start = (HEIGHT / 2) - (wall_slice_info.wall_heigth / 2);//debut du mur depuis le bas :(
    end = (HEIGHT / 2) + (wall_slice_info.wall_heigth  / 2);//fin du mur en haut
    draw_wall(game, &wall_slice_info, start, end);
}

//render collumn with texture
int ft_paint_collumn_with_texture(t_game_data *game, float alpha_tmp, float y)
{
    t_pairf     player_pos;
    t_hit_info  raw_data_fisheyed;
    t_hit_info  corrected_data;

    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;
    raw_data_fisheyed = get_wall_data(game, alpha_tmp, &player_pos.y, &player_pos.x);
    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;

    corrected_data = raw_data_fisheyed;
    corrected_data.wall_dst *= cos(alpha_tmp - game->angle_fov);
    if (corrected_data.wall_dst < 0.01)
		corrected_data.wall_dst = 0.01;
    draw_vertical_line_with_texture(game, (t_wall_slice_info){
        .wall_heigth = (HEIGHT / corrected_data.wall_dst),
        .axis_wall_hit = raw_data_fisheyed.axis_hit,
        .texture = get_wall_texture(game, raw_data_fisheyed.axis_hit, alpha_tmp),
        .offset_x = get_offset_texture(&player_pos, &raw_data_fisheyed, alpha_tmp),
        .texture_pos = 0,
        .y = y,
        .angle = alpha_tmp
    });
    return SUCCESS;
}

int ft_raycast_the_wall(t_game_data *game)
{
    float   delta;
    float   alpha_tmp;
    float    y;

    delta = FOV / WIDTH;
    alpha_tmp = game->angle_fov - (FOV / 2);
    y = WIDTH;
    while (y > 0)
    {
        if (ft_paint_collumn_with_texture(game, alpha_tmp, y) == FAILURE)
            return (FAILURE);
        y--;
        alpha_tmp = alpha_tmp + delta;
    }
    return SUCCESS;
}
