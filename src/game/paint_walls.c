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
void    draw_wall(t_game_data *game, t_param_w *params, int start, int end) //TODO: Rename de mort a faire
{
    unsigned int	color;
	float			tex_pos;
	float			step;

	//detricotage a faire : why texture pos et tex pos ??
    step = 1.0f * params->texture->height / (int)params->impact.wall_dst; //(plus on est loin plus les pas sont grands) = plus on saute de pix dans la colonne
    tex_pos = (start - HEIGHT / 2 + params->impact.wall_dst / 2) * step;
    params->texture_pos = (int)params->texture_x;  //texture_x = colonne ou on est dans la texture 
    while (start < end)
    {
		int tx = params->texture_pos; //je choppe les co precis dans la texture
        int ty = (int)tex_pos & (params->texture->height - 1);
        color = what_color_is_hit_pixel(params->texture, tx, ty); //je choppe couleur dans texture
        put_pixel(game->data->infra.img_nxt, color, params->y, start); //peint le pixel
        tex_pos += step; //et j'avance dans la texture (plus on est loin plus les pas sont grands)
        start++;
    }
}

//calcule les bornes de la ou on va repeindre la colonne avec les pix de la texture
void   draw_vertical_line_with_texture(t_game_data *game, t_param_w params)
{
    float	start;
	float	end;

    params.impact.wall_dst = (float)HEIGHT / params.impact.wall_dst; //calcul de la hauteur du mur a lecran
    start = ((float)HEIGHT / 2.0f) - (params.impact.wall_dst / 2.0f);//calcul  ou commence le et finit le mur su rlecran
    end = ((float)HEIGHT / 2.0f) + (params.impact.wall_dst  / 2.0f); //wtf pourquoi on s'embete a tout cast en float alors au'on a des int en arg dans la ft ensuite
    draw_wall(game, &params, start, end);
}

//TODO: peut-etre rename param en ray_data

int	ft_paint_one_pix_collumn(t_game_data *game, float alpha_tmp, float y)
{
	t_pairf		player_pos;
	t_impact_data	impact;
	float		wall_x; //la coordonee x de la case du mur ????
	int			texture_x;
	t_asset		*texture;

	player_pos.x = game->pos_x; //comme j'y touche pas = simplifiable
	player_pos.y = game->pos_y;

	impact = get_impact_data_with_dda(game, alpha_tmp, &player_pos.y, &player_pos.x);

	impact.wall_dst *= cosf(alpha_tmp - game->angle); //correction de donees antifisheye
	if (impact.wall_dst < 0.01f) //on bloque la distance du mur a 0.01, car risque de div pr 0 et crash
		impact.wall_dst = 0.01f;
	//meybe rassembler ces 3 lignes dans un corrected /adjusted data

	if (impact.axis_hit == HORIZ_X) //utiliser l'autre co du point d'impact pour situer ou se trouve la col dans la texture
		wall_x = impact.hit.y;
	else
		wall_x = impact.hit.x;
	wall_x -= floorf(wall_x); //obtenir un truc entre 0 et 1

	texture = get_texture_by_orientation(game, impact.axis_hit, alpha_tmp);

	//tout ce bloc la en une fonction dont le but est de me donner le "numero de la col frappee par le rayon dans la texture)
	if (!texture || !texture->addr)
		return (FAILURE);
	texture_x = (int)(wall_x * (float)texture->width); //co x dans ma texture
	if (impact.axis_hit == HORIZ_X && cosf(alpha_tmp) < 0.0f) // mettre un ou fait la meme ?
		texture_x = texture->width - texture_x - 1;
	if (impact.axis_hit == VERTI_Y && sinf(alpha_tmp) > 0.0f)
		texture_x = texture->width - texture_x - 1;
	if (texture_x < 0 || texture_x >= texture->width)
		return (FAILURE);

	//ci apres, faire une fonction dediee a init la structure (on la decla et on la b0 par ex)
	draw_vertical_line_with_texture(game, (t_param_w){
		.impact = impact,
		.texture = texture,
		.texture_x = texture_x,
		.texture_pos = 0.0f,
		.y = y,
		.alpha = alpha_tmp
	});
	return (SUCCESS);
}

