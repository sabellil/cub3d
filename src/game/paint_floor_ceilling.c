/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_floor_ceilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:39:08 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/17 18:08:39 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	what_color_is_this_pixel(double x, double y, t_infra *infra)
{
	int	color;

	color = infra->data->game.floor_color;
	(void)x;
	if (y <= HEIGHT / infra->ratio)
		color = infra->data->game.ceiling_color;
	return (color);
}

void	put_pixel(t_img *image, int color, int x, int y)
{
	int		shifting;
	char	*pix_target;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	shifting = y * image->grid_len + x * (image->bit_per_pix / 8);
	pix_target = image->pix_grid + shifting;
	*(unsigned int *)pix_target = color;
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
