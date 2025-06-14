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
/*   Created: 2025/06/06 16:17:58 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 16:17:58 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	key_up(t_infra *infra)
{
	infra->data->game.pos_y--;
	return (SUCCESS);
}

int	key_down(t_infra *infra)
{
	infra->data->game.pos_y++;
	return (SUCCESS);
}

int	key_left(t_infra *infra)
{
	infra->data->game.pos_x--;
	return (SUCCESS);
}

int	key_right(t_infra *infra)
{
	infra->data->game.pos_x++;
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
	t_infra	*infra;

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
	if (keycode == XK_Up || keycode == XK_w || keycode == XK_W)
		key_up(infra); //haut = moove y++
	if (keycode == XK_Down || keycode == XK_s || keycode == XK_S)
		key_down(infra); //bas = moove y--
	if (keycode == XK_d || keycode == XK_D)
		key_right(infra); //key right droite = moove x++
	if (keycode == XK_a || keycode == XK_A)
		key_left(infra); //key righht gauche = moove x--
	if (keycode == XK_Left)
		key_turn_left(infra); //angle ++
	if (keycode == XK_Right)
		key_turn_right(infra); //angle --
	return (SUCCESS);
}

//ICI COREDUMP
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