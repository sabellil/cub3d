/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/07/28 16:10:53 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/28 16:10:53 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	ft_setup_hooks(t_data *data)
{
	t_infra *infra;

	infra = &data->infra;
	mlx_hook(infra->win, DestroyNotify, StructureNotifyMask, close_window,
		infra);
	mlx_hook(infra->win, KeyPress, KeyPressMask, on_key_press, infra);
	mlx_hook(infra->win, KeyRelease, KeyReleaseMask, on_key_release, infra);
	mlx_loop_hook(infra->mlx, handle_keypress, infra);
}

int	handle_keypress(t_infra *infra)
{
	t_game_data *game;

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
