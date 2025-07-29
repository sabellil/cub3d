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
		return (COLOR_INVALID);
	if (hit_x < 0 || hit_x >= texture->width || hit_y < 0 || hit_y >= texture->height)
		return (COLOR_INVALID);
	char_of_pix_on_xpm = texture->addr 
		+ (hit_y * texture->line_len) 
		+ (hit_x * (texture->bpp / 8));
	color = *(unsigned int *)char_of_pix_on_xpm;
	return (color);
}

t_asset		*get_texture_by_orientation(t_game_data *game, int axis_hit, float alpha)
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

//paint segment/colonne du mur de maniere realiste par rapport a la perspective
void    paint_one_column_with_tex(t_game_data *game, t_ray_data *ray, int draw_start, int draw_end) //TODO: Rename de mort a faire
{
    unsigned int	color;
	float			tex_y_pos;
	float			step;

	//les draw machin draw end pas forcement adapte. c'est peut etre plus draw actual et draw max ou truc du genre

	//detricotage a faire : why texture pos et tex pos ??
    step = 1.0f * ray->texture->height / (int)ray->impact.wall_dst; //(plus on est loin plus les pas sont grands) = plus on saute de pix dans la colonne
    tex_y_pos = (draw_start - HEIGHT / 2 + ray->impact.wall_dst / 2) * step;
    ray->tex_x_pos = (int)ray->texture_x;  //texture_x = colonne ou on est dans la texture 
    while (draw_start < draw_end)
    {
		int tx = ray->tex_x_pos; //je choppe les co precis dans la texture
        int ty = (int)tex_y_pos & (ray->texture->height - 1);
        color = what_color_is_hit_pixel(ray->texture, tx, ty); //je choppe couleur dans texture
        put_pixel(game->data->infra.img_nxt, color, ray->y, draw_start); //peint le pixel
        tex_y_pos += step; //et j'avance dans la texture (plus on est loin plus les pas sont grands)
        draw_start++;
    }
}

//calcule les bornes de la ou on va repeindre la colonne avec les pix de la texture
void   draw_wall_line_with_texture(t_game_data *game, t_ray_data ray)
{
    float	start;
	float	end;

    start = ((float)HEIGHT / 2.0f) - (ray.impact.wall_dst / 2.0f);//calcul  ou commence le et finit le mur su rlecran
    end = ((float)HEIGHT / 2.0f) + (ray.impact.wall_dst  / 2.0f); //wtf pourquoi on s'embete a tout cast en float alors au'on a des int en arg dans la ft ensuite
    paint_one_column_with_tex(game, &ray, start, end);
}
//bigger wall on screen, fix fisheye, div_0 protec 
void	fix_fisheye_effect(float *raw_value, float alpha_tmp, float alpha_global)
{
	float	result;

	result =  *raw_value * cosf(alpha_tmp - alpha_global);
	if (result < 0.01f)
		result = 0.01f;
	result = HEIGHT / result;
	*raw_value = result;
}

// int	get_id_collumn_hit()
// {
// 	int	id;
// 	float 

// 	id_coll = 0;

// }

t_ray_data	init_ray_data(t_impact_data impact, t_asset *texture, int tex_hit_coord_x, int y, float angle_tmp)
{
	t_ray_data	ray_data;

	ray_data.impact = impact;
	ray_data.texture = texture;
	ray_data.texture_x = tex_hit_coord_x;
	ray_data.tex_x_pos = 0.0f;
	ray_data.y = y;
	ray_data.alpha = angle_tmp;
	return (ray_data);
}


int	ft_paint_one_pix_collumn(t_game_data *game, float angle_tmp, float y)
{
	t_asset			*texture;
	t_impact_data	impact;
	float			wall_hit_coord_x;
	float			wall_hit_ratio; 
	int				tex_hit_coord_x;

	impact = get_impact_data_with_dda(game, angle_tmp, &game->pos_y, &game->pos_x);
	texture = get_texture_by_orientation(game, impact.axis_hit, angle_tmp);
	if (!texture || !texture->addr)
		return (FAILURE);
	fix_fisheye_effect(&impact.wall_dst, angle_tmp, game->angle);
	wall_hit_coord_x = impact.hit.x;
	if (impact.axis_hit == HORIZ_X) //utiliser l'autre co du point d'impact pour situer ou se trouve la col dans la texture
		wall_hit_coord_x = impact.hit.y;
	wall_hit_ratio = wall_hit_coord_x - floorf(wall_hit_coord_x);
	tex_hit_coord_x = (int)(wall_hit_ratio * (float)texture->width); //co x dans ma texture
	if ((impact.axis_hit == HORIZ_X && cosf(angle_tmp) < 0.0f)
		|| (impact.axis_hit == VERTI_Y && sinf(angle_tmp) > 0.0f))
		tex_hit_coord_x = texture->width - tex_hit_coord_x - 1;
	if (tex_hit_coord_x < 0 || tex_hit_coord_x >= texture->width)
		return (FAILURE);
	draw_wall_line_with_texture(game,
		init_ray_data(impact, texture, tex_hit_coord_x, y, angle_tmp));
	return (SUCCESS);
}

