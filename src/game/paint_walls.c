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

static float	get_ratio_texture(const t_pairf *player_pos, 
    t_hit_info *hit_info, float alpha)
{
    float   offset_texture;
    

    (void)alpha;
    (void)player_pos;
    printf("crossX: %f crossY: %f\n", hit_info->cross.x, hit_info->cross.y);
    if (hit_info->axis_hit == X_AXIS)
	    offset_texture = hit_info->cross.y - floorf(hit_info->cross.y);
    else
	    offset_texture = hit_info->cross.x - floorf(hit_info->cross.x);

    // float	hit_point;
    // (void)hit_info->cross;
	// if (hit_info->axis_hit == X_AXIS)
	// 	hit_point = player_pos->y + (hit_info->wall_dst * sinf(alpha));
	// else
	// 	hit_point = player_pos->x + (hit_info->wall_dst * cosf(alpha));
    // offset_texture = fabsf(hit_point - floorf(hit_point));

    // printf("offset: %f\n", offset_texture);
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


void    draw_wall(t_game_data *game, t_wall_slice *actwall_slice, int start, int end) 
{
    unsigned int    color;
	float			pix_collumn;
	float			step;


    step = actwall_slice->texture->height / (float)actwall_slice->wall_heigth;
    pix_collumn = (start - HEIGHT / 2 + actwall_slice->wall_heigth / 2) * step;
    actwall_slice->hit_pix_tex = ft_min(actwall_slice->texture->width, actwall_slice->hit_ratio_tex * actwall_slice->texture->width) /*(TEXTURE_SIZE)*/;
    
    if (actwall_slice->axis_wall_hit == 0 && cosf(actwall_slice->angle) > 0)
        actwall_slice->hit_pix_tex = actwall_slice->texture->width - actwall_slice->hit_pix_tex - 1;
    else if (actwall_slice->axis_wall_hit  == 1 && sinf(actwall_slice->angle) < 0)
        actwall_slice->hit_pix_tex = actwall_slice->texture->width - actwall_slice->hit_pix_tex - 1;
    
    while (start < end)
    {
		color = get_pixel_from_texture(actwall_slice->texture, actwall_slice->hit_pix_tex,
				((int)pix_collumn & (actwall_slice->texture->height - 1)));
        put_pixel(game->data->infra.img_nxt, color, actwall_slice->collumn_id, start);
        pix_collumn += step;
        ++start;
    }
}

void   draw_vertical_line_with_texture(t_game_data *game, t_wall_slice wall_slice_info)
{
    int	start;
	int	end;

    start = (HEIGHT / 2) - (wall_slice_info.wall_heigth / 2);//debut du mur depuis le bas :(
    end = (HEIGHT / 2) + (wall_slice_info.wall_heigth  / 2);//fin du mur en haut
    draw_wall(game, &wall_slice_info, start, end);
}

t_wall_slice    get_slice_data(t_game_data *game, t_hit_info hit, float alpha_tmp, int collumn_id, t_pairf player_pos)
{
        t_wall_slice    k;

        k.wall_heigth = (HEIGHT / hit.wall_dst);
        k.axis_wall_hit = hit.axis_hit;
        k.texture = get_wall_texture(game, hit.axis_hit, alpha_tmp);
        k.hit_ratio_tex = get_ratio_texture(&player_pos, &hit, alpha_tmp);
        k.hit_pix_tex = player_pos.x;
        k.collumn_id = collumn_id;
        k.angle = alpha_tmp;


        // printf("k.hit_pix_tex: %i\n", k.hit_pix_tex);
        // printf("wh:%i awh:%i ox:%f tp:%i ci:%f a:%f \n", k.wall_heigth,
        // k.axis_wall_hit,
        // k.offset_x,
        // k.texture_pos,
        // k.collumn_id,
        // k.angle);

        return (k);
}

//render collumn with texture
int ft_paint_collumn_with_texture(t_game_data *game, float alpha_tmp, float collumn_id)
{
    t_pairf         player_pos;
    t_hit_info      raw_data_fisheyed;
    t_hit_info      corrected_data;
    t_wall_slice    slice;

    player_pos.x = game->pos_x;
    player_pos.y = game->pos_y;
    raw_data_fisheyed = get_wall_data(game, alpha_tmp, &player_pos.y, &player_pos.x);
    // player_pos.x = game->pos_x;
    // player_pos.y = game->pos_y;
    // printf("-----------------------posX: %f posY: %f\n", game->pos_x, game->pos_y);

    corrected_data = raw_data_fisheyed;
    corrected_data.wall_dst *= cos(alpha_tmp - game->angle_fov);
    if (corrected_data.wall_dst < 0.01)
		corrected_data.wall_dst = 0.01;
    
    slice = get_slice_data(game, corrected_data, alpha_tmp, collumn_id, player_pos);

    draw_vertical_line_with_texture(game, slice);
    return SUCCESS;
}

int ft_raycast_the_wall(t_game_data *game)
{
    float   step_angle;
    float   ray_angle;
    float   column_pix_id;

    step_angle = FOV / WIDTH;
    ray_angle = game->angle_fov - (FOV / 2);
    column_pix_id = WIDTH;
    while (column_pix_id > 0)
    {
        if (ft_paint_collumn_with_texture(game, ray_angle, column_pix_id) == FAILURE)
            return (FAILURE);
        column_pix_id--;
        ray_angle = ray_angle + step_angle;
    }
    return SUCCESS;
}
