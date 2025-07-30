/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_image_and_render_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:39:08 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/30 14:35:56 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed_bonus.h"

void	paint_ground_and_sky(t_img *ptr, t_infra *infra)
{
	double			x;
	double			y;
	unsigned int	color;

	x = 0.0;
	y = HEIGHT;
	color = 0;
	while (y-- > 0)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			color = infra->data->game.floor_color;
			if (y <= HEIGHT / infra->ratio)
				color = infra->data->game.ceiling_color;
			put_pixel(ptr, color, x, y);
		}
	}
}

int	paint_the_wall(t_game_data *game)
{
	float	delta;
	float	alpha_tmp;
	float	img_x;

	delta = FOV / WIDTH;
	alpha_tmp = game->angle - (FOV / 2);
	img_x = 0.0f;
	while (img_x < 1280.0f)
	{
		if (draw_wall_line_with_texture(game, alpha_tmp, img_x) == FAILURE)
			return (FAILURE);
		img_x++;
		alpha_tmp = alpha_tmp + delta;
	}
	return (SUCCESS);
}

void	swap_buffer(t_infra *infra)
{
	t_img	*temp;

	temp = infra->img_now;
	infra->img_now = infra->img_nxt;
	infra->img_nxt = temp;
}

int	ft_render(t_data *data)
{
	t_infra	*infra;

	infra = &data->infra;
	paint_ground_and_sky(infra->img_nxt, infra);
	paint_the_wall(&data->game);
	draw_minimap(data);
	mlx_put_image_to_window(infra->mlx, infra->win, infra->img_now->new_img, 0,
		0);
	swap_buffer(infra);
	return (SUCCESS);
}
