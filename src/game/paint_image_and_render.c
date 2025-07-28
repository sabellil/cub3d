/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_image_and_render.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:39:08 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/28 16:09:24 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

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
	float	y;

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
	mlx_put_image_to_window(infra->mlx, infra->win, infra->img_now->new_img, 0,
		0);
	swap_buffer(infra);
	return (SUCCESS);
}
