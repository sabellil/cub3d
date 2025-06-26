/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_generator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:39:08 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/26 12:33:14 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	int	color;

	color = (255 << 24) | (r << 16) | (g << 8) | b;
	return (color);
}

void	put_pixel(t_img *image, int color, int x, int y)
{
	int		shifting;
	char	*pix_target;

	shifting = y * image->grid_len + x * (image->bit_per_pix / 8);
	pix_target = image->pix_grid + shifting;
	*(unsigned int *)pix_target = color;
}

void	swap_buffer(t_infra *infra)
{
	t_img	*temp;

	temp = infra->img_now;
	infra->img_now = infra->img_nxt;
	infra->img_nxt = temp;
}

void	paint_each_pixel(t_img *ptr, t_infra *skelet)
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
			color = what_color_is_this_pixel(x, y, skelet);
			put_pixel(ptr, color, x, y);
		}
	}
}

int	ft_render(t_data *data)
{
	t_infra	*infra;

	infra = &data->infra;
	paint_each_pixel(infra->img_nxt, infra);
	ft_paint_the_wall(&data->game);
	draw_minimap(data);
	mlx_put_image_to_window(infra->mlx, infra->win,
		infra->img_now->new_img, 0, 0);
	swap_buffer(infra);
	return (SUCCESS);
}
