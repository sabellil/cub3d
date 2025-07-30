/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/30 13:48:58 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

// paint segment/colonne du mur de maniere realiste par rapport a la perspective
void	paint_one_column_with_tex(t_game_data *game, t_ray_data *ray,
		int draw_start, int draw_end)
{
	unsigned int	color;
	float			tex_y_pos;
	float			step;
	int				tx;
	int				ty;

	step = 1.0f * ray->texture->height / (int)ray->impact.wall_dst;
		//(plus on est loin plus les pas sont grands) = plus on saute de pix dans la colonne
	tex_y_pos = (draw_start - HEIGHT / 2 + ray->impact.wall_dst / 2) * step;
	ray->tex_x_pos = (int)ray->texture_x;
		// texture_x = colonne ou on est dans la texture
	while (draw_start < draw_end)
	{
		tx = ray->tex_x_pos; // je choppe les co precis dans la texture
		ty = (int)tex_y_pos & (ray->texture->height - 1);
		color = what_color_is_hit_pixel(ray->texture, tx, ty);
			// je choppe couleur dans texture
		put_pixel(game->data->infra.img_nxt, color, ray->x_img, draw_start);
			// peint le pixel
		tex_y_pos += step;
			// et j'avance dans la texture (plus on est loin plus les pas sont grands)
		draw_start++;
	}
}

// calcule les bornes de la ou on va repeindre la colonne avec les pix de la texture
int	draw_wall_line_with_texture(t_game_data *game, float angle_tmp,
		float x_img)
{
	int			start;
	int			end;
	t_ray_data	*ray;

	ray = get_ray_data_to_draw_wall_line(game, angle_tmp, x_img);
	if (ray == NULL)
		return (FAILURE);
	start = (HEIGHT / 2) - (ray->impact.wall_dst / 2);
	end = (HEIGHT / 2) + (ray->impact.wall_dst / 2);
	paint_one_column_with_tex(game, ray, start, end);
	free(ray);
	return (SUCCESS);
}
