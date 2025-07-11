/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:42:21 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/11 13:28:54 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	draw_square(t_img *img, t_square sq)
{
	int	i;
	int	j;

	i = 0;
	while (i < sq.size)
	{
		j = 0;
		while (j < sq.size)
		{
			put_pixel(img, sq.color, sq.x + j, sq.y + i);
			j++;
		}
		i++;
	}
}

static void	draw_map_tile(t_img *img, char tile, t_tile_info info)
{
	t_square	sq;

	if (tile == '1')
		sq.color = 0x222222;
	else if (tile == '0')
		sq.color = 0xffffff;
	else
		sq.color = 0x222222;
	sq.x = info.x * info.size;
	sq.y = info.y * info.size;
	sq.size = info.size;
	draw_square(img, sq);
}

static void	draw_minimap_tiles(t_data *data, t_img *img, int tile_size)
{
	int			y;
	int			x;
	char		*current_line;
	t_tile_info	info;

	info.size = tile_size;
	y = 0;
	while (y < data->game.map_height)
	{
		info.y = data->game.map_height - 1 - y;
		current_line = data->game.map[info.y];
		x = 0;
		while (x < data->game.map_width)
		{
			if (x < (int)ft_strlen(current_line))
				info.tile = current_line[x];
			else
				info.tile = '1';
			info.x = x;
			draw_map_tile(img, info.tile, info);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	t_img		*img;
	t_square	sq;
	int			tile_size;

	tile_size = 20;
	img = data->infra.img_nxt;
	draw_minimap_tiles(data, img, tile_size);
	sq.size = 4;
	sq.color = 0xFF0000;
	sq.x = (int)((data->game.pos_y) * tile_size - sq.size / 2.0);
	sq.y = (int)((data->game.pos_x) * tile_size - sq.size / 2.0);
	draw_square(img, sq);
}
