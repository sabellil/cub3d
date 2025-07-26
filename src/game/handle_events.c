/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:50:03 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/15 16:50:03 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	ft_setup_hooks(t_data *data)
{
	t_infra	*infra;

	infra = &data->infra;
	mlx_hook(infra->win, DestroyNotify, StructureNotifyMask,
		close_window, infra);
	mlx_key_hook(infra->win, handle_keypress, infra);
}

int	handle_keypress(int keycode, t_infra *infra)
{
	if (keycode == XK_Escape)
		close_window(infra);
	if (keycode == XK_w || keycode == XK_W)
		move_up(infra);
	if (keycode == XK_s || keycode == XK_S)
		move_down(infra);
	if (keycode == XK_d || keycode == XK_D)
		move_right(infra);
	if (keycode == XK_a || keycode == XK_A)
		move_left(infra);
	if (keycode == XK_Left || keycode == XK_Right)
		move_turn(infra, keycode);
	//printf("x: %f / y: %f / A: %f \n", infra->data->game.pos_x, infra->data->game.pos_y, infra->data->game.angle);
	return (SUCCESS);
}

int	close_window(t_infra *infra)
{
	destroy_images_and_window(infra);
	free_mlx_and_data(infra);
	exit(SUCCESS);
}
