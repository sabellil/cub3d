/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_generator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:39:08 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/24 14:40:09 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

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
static void	test_is_it_a_wall(t_game_data *game)
{
	float test_coords[][2] = {
		{1.0f, 1.0f},
		{0.0f, 0.0f},
		{5.0f, 3.0f},
		{-1.0f, 2.0f},
		{game->map_width - 0.1f, game->map_height - 0.1f},
		{game->map_width, game->map_height},
		{2.5f, 1.5f},
	};
	int i;
	int nb_tests = sizeof(test_coords) / sizeof(test_coords[0]);

	printf("=== Test ft_is_it_a_wall ===\n");
	i = 0;
	while (i < nb_tests)
	{
		float x = test_coords[i][0];
		float y = test_coords[i][1];
		printf("Test #%d - Position : (%.2f, %.2f)\n", i + 1, x, y);
		ft_is_it_a_wall(game, x, y);
		i++;
	}
	printf("===========================\n\n");
}

int	ft_render(t_data *data)
{
	t_infra	*infra;

	infra = &data->infra;
	paint_each_pixel(infra->img_nxt, infra);
// print_map(data->game.map, data->game.map_height);//TODO : A virer, juste poue comparer avec resultat ft is it a map
// test_is_it_a_wall(&data->game);//A virer 
	draw_minimap(data);
	mlx_put_image_to_window(infra->mlx, infra->win,
		infra->img_now->new_img, 0, 0);
	swap_buffer(infra);
	return (SUCCESS);
}
