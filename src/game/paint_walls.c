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


unsigned int	what_color_is_hit_pixel(t_asset *texture, int hit_x, int hit_y)
{
	char	*char_of_pix_on_xpm;
	int		color;

	if (!texture || !texture->addr)
		return (0);//TODO: difine 0 = black - ou c'est une protec ?
	if (hit_x < 0 || hit_x >= texture->width || hit_y < 0 || hit_y >= texture->height)
		return (0); //ici c'est une protec. est-ce reelement un retour de couleur ? 
	char_of_pix_on_xpm = texture->addr + (hit_y * texture->line_len) + (hit_x
			* (texture->bpp / 8));
	color = *(unsigned int *)char_of_pix_on_xpm;
	return (color);
}


t_asset *get_texture_by_orientation(t_game_data *game, int axis_hit, float alpha) 
{
	t_asset	*texture;

	texture = NULL;
	if (axis_hit == HORIZ_X) 
	{
        if (cosf(alpha) >= 0)
            texture = &game->tex_ea;
		else
        	texture = &game->tex_we;
    }
    if (axis_hit == VERTI_Y) 
	{
        if (sinf(alpha) >= 0)
            texture = &game->tex_no;
		else
        	texture = &game->tex_so;
    }
	return(texture);
}

void    draw_wall(t_game_data *game, t_param_w *params, int start, int end) 
{
    unsigned int color;
	float			tex_pos;
	float			step;


    step = 1.0f * params->texture->height / (int)params->impact.wall_dst;
    tex_pos = (start - HEIGHT / 2 + params->impact.wall_dst / 2) * step;
    // params->texture_pos = ft_min(params->texture->width, params->texture_x * params->texture->width) /*(TEXTURE_SIZE)*/;

    params->texture_pos = (int)params->texture_x;   
    while (start < end)
    {
		int tx = params->texture_pos;
        int ty = (int)tex_pos & (params->texture->height - 1);
        color = what_color_is_hit_pixel(params->texture, tx, ty);
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

    params.impact.wall_dst = (float)HEIGHT / params.impact.wall_dst; //calcul de la hauteur du mur a lecran
    start = ((float)HEIGHT / 2.0f) - (params.impact.wall_dst / 2.0f);//calcul  ou commence le et finit le mur su rlecran
    end = ((float)HEIGHT / 2.0f) + (params.impact.wall_dst  / 2.0f);
    draw_wall(game, &params, start, end);
}

int	ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float y)
{
	t_pairf		player_pos;
	t_impact_data	dst_side;
	float		wall_x;
	int			texture_x;
	t_asset		*texture;

	player_pos.x = game->pos_x;
	player_pos.y = game->pos_y;

	dst_side = get_impact_data_with_dda(game, alpha_tmp, &player_pos.y, &player_pos.x);

	dst_side.wall_dst *= cosf(alpha_tmp - game->angle);
	if (dst_side.wall_dst < 0.01f)
		dst_side.wall_dst = 0.01f;

	if (dst_side.axis_hit == 0)
		wall_x = dst_side.hit.y;
	else
		wall_x = dst_side.hit.x;
	wall_x -= floorf(wall_x);

	texture = get_texture_by_orientation(game, dst_side.axis_hit, alpha_tmp);
	if (!texture || !texture->addr)
	{
		printf("NULL texture !\n");
		return (FAILURE);
	}

	texture_x = (int)(wall_x * (float)texture->width);

	if (dst_side.axis_hit == 0 && cosf(alpha_tmp) < 0.0f)
		texture_x = texture->width - texture_x - 1;
	if (dst_side.axis_hit == 1 && sinf(alpha_tmp) > 0.0f)
		texture_x = texture->width - texture_x - 1;

	if (texture_x < 0 || texture_x >= texture->width)
	{
		printf("BAD texture_x: %d / texture->width: %d\n", texture_x, texture->width);
		return (FAILURE);
	}

	draw_vertical_line_with_texture(game, (t_param_w){
		.impact = dst_side,
		.texture = texture,
		.texture_x = texture_x,
		.texture_pos = 0.0f,
		.y = y,
		.alpha = alpha_tmp
	});
	return (SUCCESS);
}

