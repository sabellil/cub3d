/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_generator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:39:08 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/17 18:10:25 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

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
	paint_each_pixel(infra->img_nxt, infra);
	ft_paint_the_wall(&data->game);
	draw_minimap(data);
	mlx_put_image_to_window(infra->mlx, infra->win,
		infra->img_now->new_img, 0, 0);
	swap_buffer(infra);
	return (SUCCESS);
}
