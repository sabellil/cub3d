/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/06/23 12:56:53 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/23 12:56:53 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"


int	key_up(t_infra *infra)
{
	infra->data->game.pos_y -= 0.2;
	return (SUCCESS);
}

int	key_down(t_infra *infra)
{
	infra->data->game.pos_y += 0.2;
	return (SUCCESS);
}

int	key_left(t_infra *infra)
{
	infra->data->game.pos_x -= 0.2;
	return (SUCCESS);
}

int	key_right(t_infra *infra)
{
	infra->data->game.pos_x += 0.2;
	return (SUCCESS);
}

int	key_turn_left(t_infra *infra)
{
	infra->ratio = infra->ratio + 0.2;
	return (SUCCESS);
}

int	key_turn_right(t_infra *infra)
{
	if (infra->ratio > 1.3)
		infra->ratio = infra->ratio - 0.2;
	return (SUCCESS);
}

void	ft_setup_hooks(t_data *data)
{
	t_infra *infra;

	infra = &data->infra;
	mlx_hook(infra->win, DestroyNotify, StructureNotifyMask, close_window,
			infra);
	mlx_key_hook(infra->win, handle_keypress, infra);
	//mlx_mouse_hook(infra->win, handle_mouse_event, infra);
}

// #define XK_KP_Left                       0xff96
// #define XK_KP_Up                         0xff97
// #define XK_KP_Right                      0xff98
// #define XK_KP_Down                       0xff99

int	handle_keypress(int keycode, t_infra *infra)
{
	if (keycode == XK_Escape)
		close_window(infra);
	if (keycode == XK_w || keycode == XK_W)
		move_up(infra); //bas = moove y--
	if (keycode == XK_s || keycode == XK_S)
		move_down(infra); //haut = moove y++
	if (keycode == XK_d || keycode == XK_D)
		move_right(infra); //key right droite = moove x++
	if (keycode == XK_a || keycode == XK_A)
		move_left(infra); //key righht gauche = moove x--
	if (keycode == XK_Left || keycode == XK_Right)
		move_turn(infra, keycode);
	// printf("x: %f / y: %f / A: %f \n", infra->data->game.pos_x, infra->data->game.pos_y, infra->data->game.angle);
	return (SUCCESS);
}

int	close_window(t_infra *infra)
{
	destroy_images_and_window(infra);
	free_mlx_and_data(infra);
	exit(SUCCESS);
}

/*int	handle_mouse_event(int button, int x, int y, t_infra *infra)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
	{
        printf("scroll up\n");
	}
	if (button == SCROLL_DOWN)
	{
        printf("scroll up\n");
	}
	return (SUCCESS);
}*/