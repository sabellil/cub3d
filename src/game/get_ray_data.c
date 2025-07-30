/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/30 14:08:06 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

// bigger wall on screen, fix fisheye, div_0 protec
void	fix_fisheye_effect(float *raw_value, float alpha_tmp,
		float alpha_global)
{
	float	result;

	result = *raw_value * cosf(alpha_tmp - alpha_global);
	if (result < 0.01f)
		result = 0.01f;
	result = HEIGHT / result;
	*raw_value = result;
}

int	get_x_texture(t_asset *texture, t_impact_data impact, float angle_tmp)
{
	float	wall_hit_coord_x;
	float	wall_hit_ratio;
	int		tex_hit_coord_x;

	wall_hit_coord_x = impact.hit.x;
	if (impact.axis_hit == HORIZ_X)
		// utiliser l'autre co du point d'impact pour situer ou se trouve la col dans la texture
		wall_hit_coord_x = impact.hit.y;
	wall_hit_ratio = wall_hit_coord_x - floorf(wall_hit_coord_x);
	tex_hit_coord_x = (int)(wall_hit_ratio * (float)texture->width);
		// co x dans ma texture
	if ((impact.axis_hit == HORIZ_X && cosf(angle_tmp) < 0.0f)
		|| (impact.axis_hit == VERTI_Y && sinf(angle_tmp) > 0.0f))
		tex_hit_coord_x = texture->width - tex_hit_coord_x -1;
	if (tex_hit_coord_x < 0 || tex_hit_coord_x >= texture->width)
		return (FAILURE);
	return (tex_hit_coord_x);
}

t_ray_data	init_ray_data(t_impact_data impact, t_asset *texture,
		int tex_hit_coord_x, int x_img, float angle_tmp)
{
	t_ray_data	ray_data;

	ft_bzero(&ray_data, sizeof(t_ray_data));
	ray_data.impact = impact;
	ray_data.texture = texture;
	ray_data.texture_x = tex_hit_coord_x;
	ray_data.tex_x_pos = 0.0f;
	ray_data.x_img = x_img;
	ray_data.alpha = angle_tmp;
	return (ray_data);
}

t_ray_data	*get_ray_data_to_draw_wall_line(t_game_data *game, float angle_tmp,
		float x_img)
{
	t_asset			*texture;
	t_impact_data	impact;
	t_ray_data		*ray_data;
	int				x_tex;

	impact = get_impact_data_with_dda(game, angle_tmp, &game->pos_y,
			&game->pos_x);
	texture = get_texture_by_orientation(game, impact.axis_hit, angle_tmp);
	if (!texture || !texture->addr)
		return (NULL);
	fix_fisheye_effect(&impact.wall_dst, angle_tmp, game->angle);
	x_tex = get_x_texture(texture, impact, angle_tmp);
	ray_data = malloc(sizeof(t_ray_data));
	if (!ray_data)
		return (NULL);
	ft_bzero(ray_data, sizeof(t_ray_data));
	ray_data->impact = impact;
	ray_data->texture = texture;
	ray_data->texture_x = x_tex;
	ray_data->tex_x_pos = 0.0f;
	ray_data->x_img = x_img;
	ray_data->alpha = angle_tmp;
	return (ray_data);
}
