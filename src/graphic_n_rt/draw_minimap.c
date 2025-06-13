/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:42:21 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/13 10:59:24 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_minimap(t_data *data)
{
	int		tile_size;
	int		y;
	int		x;
	int		color;
	char	current_case;
	t_img	*img;

	img = data->infra.img_nxt;
	tile_size = 15;
	y = 0;
	while (y < data->game.map_height)
	{
		x = 0;
		while (x < data->game.map_width)
		{
			current_case = data->game.map[y][x];
			if (current_case == '1')
				color = 0x222222;
			if (current_case == '0')
				color = 0xffffff;
			else
				color = 0x222222;
			draw_square(img, x * tile_size, y * tile_size, tile_size, color);
			x++;
		}
		y++;
	}
	draw_square(img, (int)(data->game.pos_x * tile_size), (int)(data->game.pos_y * tile_size), 4, 0xFF0000);
}

void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, color, x, y);
			j++;
		}
		i++;
	}
}
