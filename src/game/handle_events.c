/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:22:28 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/29 18:22:28 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	on_key_press(int keycode, t_infra *infra)
{
	t_game_data	*game;

	game = &infra->data->game;
	if (keycode == XK_Escape)
		close_window(infra);
	else if (keycode == XK_w || keycode == XK_W)
		game->key_w = PRESSED;
	else if (keycode == XK_s || keycode == XK_S)
		game->key_s = PRESSED;
	else if (keycode == XK_a || keycode == XK_A)
		game->key_a = PRESSED;
	else if (keycode == XK_d || keycode == XK_D)
		game->key_d = PRESSED;
	else if (keycode == XK_Left)
		game->key_left = PRESSED;
	else if (keycode == XK_Right)
		game->key_right = PRESSED;
	return (SUCCESS);
}

int	on_key_release(int keycode, t_infra *infra)
{
	t_game_data	*game;

	game = &infra->data->game;
	if (keycode == XK_w || keycode == XK_W)
		game->key_w = RELEASED;
	else if (keycode == XK_s || keycode == XK_S)
		game->key_s = RELEASED;
	else if (keycode == XK_a || keycode == XK_A)
		game->key_a = RELEASED;
	else if (keycode == XK_d || keycode == XK_D)
		game->key_d = RELEASED;
	else if (keycode == XK_Left)
		game->key_left = RELEASED;
	else if (keycode == XK_Right)
		game->key_right = RELEASED;
	return (SUCCESS);
}

void	ft_setup_hooks(t_data *data)
{
	t_infra	*infra;

	infra = &data->infra;
	mlx_hook(infra->win, DestroyNotify, StructureNotifyMask, close_window,
		infra);
	mlx_hook(infra->win, KeyPress, KeyPressMask, on_key_press, infra);
	mlx_hook(infra->win, KeyRelease, KeyReleaseMask, on_key_release, infra);
	mlx_loop_hook(infra->mlx, handle_keypress, infra);
}

int	handle_keypress(t_infra *infra)
{
	t_game_data	*game;

	game = &infra->data->game;
	if (game->key_w)
		move_up(infra);
	if (game->key_s)
		move_down(infra);
	if (game->key_a)
		move_left(infra);
	if (game->key_d)
		move_right(infra);
	if (game->key_right)
		move_turn(infra, XK_Right);
	else if (game->key_left)
		move_turn(infra, XK_Left);
	ft_render(infra->data);
	return (0);
}

int	close_window(t_infra *infra)
{
	destroy_images_and_window(infra);
	free_mlx_and_data(infra);
	exit(SUCCESS);
}
